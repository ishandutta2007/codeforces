#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#define int long long 
using namespace std;

int arbre[(1 << 19)];
map<int, int> indexs;

void modifie(int pos, int val) {
  pos += (1 << 18);
  arbre[pos] = val;
  
  while(pos != 1) {
    pos /= 2;
    arbre[pos] = arbre[2 * pos] + arbre[2 * pos + 1];
  }
}

int getSomme(int deb, int fin) {
  deb += (1 << 18);
  fin += (1 << 18);
  int somme = 0;

  while(deb < fin) {
    if(deb % 2 == 1) {
      somme += arbre[deb];
      deb++;
    }
    if(fin % 2 == 1) {
      fin--;
      somme += arbre[fin];
    }
    deb /= 2;
    fin /= 2;
  }

  return somme;
}

signed main() {
  ios_base::sync_with_stdio(false);
  int nbPoints;
  cin >> nbPoints;

  vector<pair<int, int>> points;
  for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
    int x, y;
    cin >> x >> y;
    indexs[x] = 0;
    points.push_back({y, x});
  }

  int iFois = 0;
  for(auto it = indexs.begin();it != indexs.end();it++) {
    it->second = iFois++;
  }

  sort(points.begin(), points.end());
  reverse(points.begin(), points.end());

  long long total = 0;
  for(int iDeb = 0;iDeb < nbPoints;) {
    int iFin = iDeb;

    vector<int> xs;
    while(iFin != nbPoints && points[iFin].first == points[iDeb].first) {
      modifie(indexs[points[iFin].second], 1);
      xs.push_back(indexs[points[iFin].second]);
      iFin++;
    }
    
    sort(xs.begin(), xs.end());

    long long nbXs = getSomme(0, (1 << 18) - 1);
    total += nbXs * (nbXs + 1) / 2;

    int derIndex = 0;
    for(int x : xs) {
      int nbDans = getSomme(derIndex, x);
      total -= nbDans * (nbDans + 1) / 2;
      derIndex = x + 1;
    }

    int nbDans = getSomme(derIndex, (1 << 18) - 1);
    total -= nbDans * (nbDans + 1) / 2;

    iDeb = iFin;
  }

  cout << total << endl;
  
  return 0;
}