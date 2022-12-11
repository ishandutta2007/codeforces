#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;

int degres[100 * 1000];

int main() {
  ios_base::sync_with_stdio(false);

  int nbSommets;
  cin >> nbSommets;

  for(int iSommet = 0;iSommet < nbSommets - 1;iSommet++) {
    int deb, fin;
    cin >> deb >> fin;
    deb--; fin--;
    degres[deb]++;
    degres[fin]++;
  }

  for(int iSommet = 0;iSommet < nbSommets;iSommet++) {
    if(degres[iSommet] == 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
  
  return 0;
}