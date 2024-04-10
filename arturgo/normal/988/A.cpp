#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> choisis;

int main() {
  int nbNombres, nbChoisis;
  cin >> nbNombres >> nbChoisis;

  for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
    int nombre;
    cin >> nombre;
    choisis[nombre] = iNombre;
  }

  if((int)choisis.size() < nbChoisis) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  int iChoisi = 0;
  for(pair<int, int> choisi : choisis) {
    if(iChoisi < nbChoisis) {
      cout << 1 + choisi.second << " ";
      iChoisi++;
    }
  }

  cout << endl;
  
  return 0;
}