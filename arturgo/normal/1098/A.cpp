#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define int long long
using namespace std;

vector<int> fils[200 * 1000];
int parents[200 * 1000], valeurs[200 * 1000];

int minSomme = 0;
bool estPossible = true;

int solve(int noeud, int prof, int parent) {
  if(prof % 2 == 1) {
    for(int fil : fils[noeud]) {
      solve(fil, prof + 1, valeurs[noeud]);
    }
    minSomme += parent;
    return valeurs[noeud];
  }

  int mini = 2000 * 1000 * 1000;

  for(int fil : fils[noeud]) {
    mini = min(mini, valeurs[fil]);
  }

  if(mini >= parent) {
    if(mini != 2000 * 1000 * 1000)
      minSomme += mini - parent;
  }
  else {
    estPossible = false;
  }

  for(int fil : fils[noeud]) {
    solve(fil, prof + 1, valeurs[fil] - parent - (mini - parent));
  }

  return parent - mini;
}

signed main() {
  ios_base::sync_with_stdio(false);
  int nbNoeuds;
  cin >> nbNoeuds;

  parents[0] = -1;
  for(int iNoeud = 1;iNoeud < nbNoeuds;iNoeud++) {
    cin >> parents[iNoeud];
    parents[iNoeud] -= 1;
    fils[parents[iNoeud]].push_back(iNoeud);
  }

  for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
    cin >> valeurs[iNoeud];
  }

  solve(0, 1, valeurs[0]);

  if(!estPossible)
    cout << -1 << endl;
  else
    cout << minSomme << endl;
  return 0;
}