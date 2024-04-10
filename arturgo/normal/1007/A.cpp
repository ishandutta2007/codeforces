#include <iostream>
#include <algorithm>
using namespace std;

int nombres[100 * 1000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbNombres;
  cin >> nbNombres;

  for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
    cin >> nombres[iNombre];
  }

  sort(nombres, nombres + nbNombres);

  int mini = 0;
  int nbGrands = 0;

  for(int iPlace = 0;iPlace < nbNombres;iPlace++) {
    if(nombres[mini] < nombres[iPlace]) {
      nbGrands++;
      mini++;
    }
  }

  cout << nbGrands << endl;
  return 0;
}