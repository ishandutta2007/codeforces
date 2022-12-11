#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int nbTrous, taille, nbPieces;
  cin >> nbTrous >> taille >> nbPieces;

  int minTaille = nbTrous;

  vector<int> ecarts;
  int derPos = -1;
  for(int iTrou = 0;iTrou < nbTrous;iTrou++) {
    int pos;
    cin >> pos;
    if(iTrou != 0) {
      ecarts.push_back(pos - derPos - 1);
    }
    derPos = pos;
  }

  sort(ecarts.begin(), ecarts.end());

  for(int iEcart = 0;nbTrous - iEcart > nbPieces;iEcart++) {
    minTaille += ecarts[iEcart];
  }

  cout << minTaille << endl;
  return 0;
}