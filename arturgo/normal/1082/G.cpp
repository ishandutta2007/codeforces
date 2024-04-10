#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> arcs;
vector<pair<int, int>> voisins[10000];

const int INFINI = 1000 * 1000 * 1000;
int curPasse = 0;
int derPasse[10000];

const int SOURCE = 0;
const int PUITS = 9999;
const int VILLE = 1;
const int ROUTE = 2000;

void ajoute_arc(int deb, int fin, int cap) {
  int id = arcs.size();
  voisins[deb].push_back({fin, id});
  voisins[fin].push_back({deb, id + 1});
  arcs.push_back({cap, id + 1});
  arcs.push_back({0, id});
}

bool ameliore(int noeud, int cap) {
  if(derPasse[noeud] == curPasse)
    return false;
  derPasse[noeud] = curPasse;
  
  if(noeud == PUITS)
    return true;
  
  for(pair<int, int> voisin : voisins[noeud]) {
    if(arcs[voisin.second].first >= cap && ameliore(voisin.first, cap)) {
      arcs[voisin.second].first -= cap;
      arcs[arcs[voisin.second].second].first += cap;
      return true;
    }
  }
  return false;
}

int main() {
  int nbVilles, nbRoutes;
  cin >> nbVilles >> nbRoutes;
  
  long long totalV = 0;
  for(int iVille = 0;iVille < nbVilles;iVille++) {
    int poids;
    cin >> poids;
    totalV += poids;
    ajoute_arc(SOURCE, VILLE + iVille, poids);
  }
  
  long long totalE = 0;
  for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
    int deb, fin, poids;
    cin >> deb >> fin >> poids;
    deb--; fin--;
    totalE += poids;
    ajoute_arc(VILLE + deb, ROUTE + iRoute, INFINI);
    ajoute_arc(VILLE + fin, ROUTE + iRoute, INFINI);
    ajoute_arc(ROUTE + iRoute, PUITS, poids);
  }
  
  long long minCut = 0;
  int cap = (1 << 30);
  while(cap != 0) {
    curPasse++;
    while(ameliore(SOURCE, cap)) {
      minCut += cap;
      curPasse++;
    }
    cap /= 2;
  }
  
  cout << totalE - minCut << endl;
  return 0;
}