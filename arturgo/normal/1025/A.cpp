#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int taille;
  cin >> taille;

  string chaine;
  cin >> chaine;

  if(chaine.size() == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  sort(chaine.begin(), chaine.end());

  for(int iCar = 0;iCar < (int)chaine.size() - 1;iCar++) {
    if(chaine[iCar] == chaine[iCar + 1]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}