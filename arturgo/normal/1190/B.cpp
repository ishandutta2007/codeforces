#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
 
vector<int> nbPierres;
 
signed main() {
  ios_base::sync_with_stdio(false);
  int nbPiles;
  cin >> nbPiles;
 
  int nbZeros = 0;
  for(int iPile = 0;iPile < nbPiles;iPile++) {
    int taille;
    cin >> taille;
 
    if(taille == 0)
      nbZeros++;
    nbPierres.push_back(taille);
  }

  sort(nbPierres.begin(), nbPierres.end());
  
  if(nbZeros == nbPiles) {
    cout << "cslnb" << endl;
    return 0;
  }
 
  if(nbPierres[0] == 0 && nbPierres[1] == 0) {
    cout << "cslnb" << endl;
    return 0;
  }
 
  long long somme = 0;
 
  int nbEgalites = 0;
  for(int iPile = 0;iPile < nbPiles - 1;iPile++) {
    if(nbPierres[iPile] == nbPierres[iPile + 1]) {
      if(iPile != 0 && nbPierres[iPile - 1] == nbPierres[iPile] - 1) {
	cout << "cslnb" << endl;
	return 0;
      }
 
      nbEgalites++;
    }
    
    somme += nbPierres[iPile] - iPile;
  }
 
  somme += nbPierres[nbPiles - 1] - nbPiles + 1;
  
  if(somme % 2 == 1 && nbEgalites <= 1) {
    cout << "sjfnb" << endl;
  }
  else {
    cout << "cslnb" << endl;
  }
  return 0;
}