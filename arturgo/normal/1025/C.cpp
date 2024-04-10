#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  string chaine;
  cin >> chaine;

  string conc = chaine + chaine;

  int maxTaille = 0;
  for(int iCar = 0;iCar < (int)conc.size();) {
    int fin = iCar;
    int taille = 1;
    while(fin != (int)conc.size() - 1 && conc[fin] != conc[fin + 1]) {
      fin++;
      taille++;
    }
    maxTaille = max(maxTaille, taille);
    
    iCar = fin + (iCar == fin);
  }

  cout << min((int)chaine.size(), maxTaille) << endl;
  
  return 0;
}