#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int nbVoisins[200 * 1000];

int main() {
  int nbNoeuds, s;
  cin >> nbNoeuds >> s;

  if(nbNoeuds == 2) {
    cout << s << endl;
    return 0;
  }

  for(int iArc = 1;iArc < nbNoeuds;iArc++) {
    int deb, fin;
    cin >> deb >> fin;
    nbVoisins[deb-1]++;
    nbVoisins[fin-1]++;
  }

  int nbFeuilles = 0;

  for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
    if(nbVoisins[iNoeud] == 1) {
      nbFeuilles++;
    }
  }

  cout << fixed << setprecision(15);
  cout << 2 * s / (double)nbFeuilles << endl;
  return 0;
}