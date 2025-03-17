
// OBS: Existe alguns bugs de flickering que eu não tive tempo de resolver.
// OBS: Esse código funciona corretamente apenas no Windows.

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;

struct room{
  int price;
  double taxa;
};

string load = {"███████████████████████████████████"};
int colors[] = {12, 6, 14, 2, 10};
int colorSize = sizeof(colors) / sizeof(colors[0]);
int loadSize = load.size();
int option;

void setColor(int color){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void consulta(){
  system("cls");
  double numBig;
  double numSmall;
  room bigRoom = {150, 0.06};
  room smallRoom = {100, 0.06};
  setColor(14);
  cout << setw(50) << "Quantos quartos pequenos serão limpos? ";
  cin >> numSmall;
  system("cls");
  setColor(14);
  cout << setw(50) << "Quantos quartos grandes serão limpos? ";
  cin >> numBig;
  system("cls");
  
  double custo = (numSmall * smallRoom.price) + (numBig * bigRoom.price);
  double taxa = custo * smallRoom.taxa;
  double total = (custo + taxa);
  setColor(9);
   cout << "Gerando Orçamento = ";  
  for(int i = 0; i < loadSize; i++){
    int colorIndex = (i * colorSize) / loadSize;
    setColor(colors[colorIndex]);
    cout << load[i];
    Sleep(30);
  }
  system("cls");
  setColor(9);
  cout << "================Orçamento==============\n\n";
  setColor(14);
  cout << "- Numero de quartos pequenos: " << numSmall << "\n";
  cout << "- Numero de quartos grandes: " << numBig << "\n";
  cout << "- Preço por quarto pequeno: R$" << (numSmall * smallRoom.price) << "\n";
  cout << "- Preço por quarto grande: R$" << (numBig * bigRoom.price) << "\n";
  cout << "- Custo: R$" << custo << "\n";
  setColor(9);
  cout << "==================Total================\n\n";
  setColor(12);
  cout << "- Imposto: R$" << taxa << "\n";
  setColor(10);
  cout << "$ Total: R$" << total << "\n\n\n"; 
}



int main(){
int exit;
Sleep(500);
SetConsoleOutputCP(65001);
setColor(9);
  cout << "/            Serviços de limpeza de Quartos            /\n";
  setColor(14);
  cout << "Loading = ";
    for(int i = 0; i < loadSize; i++){
    int colorIndex = (i * colorSize) / loadSize;
    setColor(colors[colorIndex]);
    cout << load[i];
    Sleep(30);
} 
    setColor(10);
    cout << endl << "Carregamento concluido!";
    Sleep(500);
    system("cls");
    inicio:
    setColor(9);
    cout << "Bem vindo ";
    setColor(10);
    system("hostname");

    setColor(14);
  cout << "[1] Agendar uma limpeza.\n";
  cout << "[2] Sair.\n";
  setColor(15);
  cin >> option;
  switch (option)
  {
  case 1:
    consulta();
    break;
  case 2:
    system("cls");
    setColor(12);
    cout << "Até mais!";
    Sleep(500);
    goto fim;
    break;
  default:
  setColor(12);
    cout << "Comando Invalido.\n";
    Sleep(500);
    system("cls");
    goto inicio;
    break;
  }
  setColor(14);
  cout << "[1] Realizar outro agendamento\n";
  cout << "[2] Sair.\n";
  setColor(15);
  cin >> exit;
  switch (exit)
  {
  case 1:
    system("cls");
    goto inicio;
    break;
  case 2:
    system("cls");
    setColor(12);
    cout << "Até mais!";
    Sleep(500);
    break;
  default:
    setColor(12);
    cout << "Comando Invalido.\n";
    Sleep(500);
    system("cls");
    goto inicio;
    break;
  }
  fim:

  return 0;
}