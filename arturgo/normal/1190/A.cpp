#include <iostream>
#include <vector>
#include <deque>
#define int long long
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  int nbObjets, nbSpeciaux, tailleFen;
  cin >> nbObjets >> nbSpeciaux >> tailleFen;

  deque<int> objets;
  for(int iSpecial = 0;iSpecial < nbSpeciaux;iSpecial++) {
    int pos;
    cin >> pos;
    objets.push_back(pos);
  }

  int nbFois = 0, dec = 1;
  while(!objets.empty()) {
    int posDeb = objets.front();
    int nDec = dec;
    
    while(!objets.empty() && (objets.front() - dec) / tailleFen == (posDeb - dec) / tailleFen) {
      objets.pop_front();
      nDec++;
    }

    dec = nDec;
    nbFois++;
  }

  cout << nbFois << endl;
  return 0;
}