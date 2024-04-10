#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parents[100 * 1000];
vector<int> fils[100 * 1000];

priority_queue<int> feuilles;

int dfs(int noeud = 0) {
  if(fils[noeud].size() == 0) {
    feuilles.push(1);
    return 1;
  }
  int somme = 0;
  for(int fil : fils[noeud])
    somme += dfs(fil);
  feuilles.push(somme);
  return somme;
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbNoeuds;
  cin >> nbNoeuds;

  parents[0] = -1;
  for(int iNoeud = 1;iNoeud < nbNoeuds;iNoeud++) {
    cin >> parents[iNoeud];
    parents[iNoeud]--;
    fils[parents[iNoeud]].push_back(iNoeud);
  }

  dfs();

  vector<int> reponses;
  for(int iFois = 0;iFois < nbNoeuds;iFois++) {
    reponses.push_back(feuilles.top());
    feuilles.pop();
  }

  while(!reponses.empty()) {
    cout << reponses.back() << " ";
    reponses.pop_back();
  }
  cout << endl;
  return 0;
}