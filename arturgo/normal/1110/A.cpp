#include <iostream>
using namespace std;

int main() {
  int base, nbNombres;
  cin >> base >> nbNombres;

  int parite = 0;
  for(int i = 0;i < nbNombres;i++) {
    int nombre;
    cin >> nombre;
    if(i == nbNombres - 1) {
      parite = (parite + nombre) % 2;
    }
    else if(base % 2 == 1) {
      parite = (parite + nombre) % 2;
    }
  }

  if(parite == 1) {
    cout << "odd" << endl;
  }
  else {
    cout << "even" << endl;
  }
  return 0;
}