#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NOEUDS = 300 * 1000;

struct Arc {
  int deb, fin, dist, id;
  Arc(int _deb = 0, int _fin = 0, int _dist = 0, int _id = 0) {
    deb = _deb;
    fin = _fin;
    dist = _dist;
    id = _id;
  }
};

bool operator < (const Arc &a, const Arc &b) {
  return a.dist < b.dist;
}

int nbNoeuds, nbArcs;
vector<Arc> arcs;
vector<int> parents(MAX_NOEUDS, -1);
vector<pair<int, int>> voisins[MAX_NOEUDS];
int curDate = 0;
int entrees[MAX_NOEUDS], sorties[MAX_NOEUDS];
int ancetres[MAX_NOEUDS][20];
int maxChemin[MAX_NOEUDS][20];
int solutions[MAX_NOEUDS];

void dfs(int noeud, int parent = -1) {
  entrees[noeud] = curDate++;

  for(int hauteur = 1;hauteur < 20;hauteur++) {
    ancetres[noeud][hauteur] = ancetres[ancetres[noeud][hauteur - 1]][hauteur - 1];
    maxChemin[noeud][hauteur] = max(maxChemin[noeud][hauteur - 1], maxChemin[ancetres[noeud][hauteur - 1]][hauteur - 1]);
  }
     
  for(pair<int, int> voisin : voisins[noeud]) {
    if(voisin.first != parent) {
      ancetres[voisin.first][0] = noeud;
      maxChemin[voisin.first][0] = voisin.second;
      dfs(voisin.first, noeud);
    }
  }
  sorties[noeud] = curDate++;
}

int Find(int a) {
  if(parents[a] == -1)
    return a;
  return (parents[a] = Find(parents[a]));
}

int estAncetre(int a, int b) {
  return entrees[a] <= entrees[b] && sorties[b] <= sorties[a];
}

int getPPAC(int a, int b) {
  if(estAncetre(a, b))
    return a;
  if(estAncetre(b, a))
    return b;
  for(int hauteur = 19;hauteur >= 0;hauteur--) {
    if(!estAncetre(ancetres[a][hauteur], b))
      a = ancetres[a][hauteur];
  }
  return ancetres[a][0];
}

int maxEntre(int a, int b) {
  if(a == b)
    return 0;
  int maxi = 0;
  for(int hauteur = 19;hauteur >= 0;hauteur--) {
    if(!estAncetre(ancetres[a][hauteur], b)) {
      maxi = max(maxi, maxChemin[a][hauteur]);
      a = ancetres[a][hauteur];
    }
  }
  maxi = max(maxi, maxChemin[a][0]);
  return maxi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> nbNoeuds >> nbArcs;

  for(int iArc = 0;iArc < nbArcs;iArc++) {
    int deb, fin, dist;
    cin >> deb >> fin >> dist;
    arcs.push_back(Arc(deb - 1, fin - 1, dist, iArc));
  }
  
  sort(arcs.begin(), arcs.end());

  long long minSomme = 0;
  for(Arc arc : arcs) {
    if(Find(arc.deb) != Find(arc.fin)) {
      parents[Find(arc.deb)] = Find(arc.fin);
      minSomme += arc.dist;
      voisins[arc.deb].push_back({arc.fin, arc.dist});
      voisins[arc.fin].push_back({arc.deb, arc.dist});
    }
  }

  dfs(0);

  for(Arc arc : arcs) {
    int ppac = getPPAC(arc.deb, arc.fin);
    solutions[arc.id] = arc.dist - max(maxEntre(arc.deb, ppac), maxEntre(arc.fin, ppac));
  }
  
  for(int iArc = 0;iArc < nbArcs;iArc++) {
    cout << minSomme + solutions[iArc] << endl;
  }
  return 0;
}