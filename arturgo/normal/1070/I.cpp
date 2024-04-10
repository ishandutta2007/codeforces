#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

struct Graph {
  int source, puits;
  vector<pair<int, int>> arcs;
  vector<vector<pair<int, int>>> voisins;

  int curPasse;
  vector<int> derPasse;
  vector<int> dists;

  int new_node() {
    voisins.push_back(vector<pair<int, int>>());
    derPasse.push_back(0);
    return voisins.size() - 1;
  }
  
  Graph() {
    source = new_node();
    puits = new_node();
    curPasse = 1;
  }

  int new_directed_edge(int deb, int fin, int cap) {
    int id = arcs.size();
    int r_id = id + 1;
    arcs.push_back({cap, r_id});
    arcs.push_back({0, id});
    voisins[deb].push_back({fin, id});
    voisins[fin].push_back({deb, r_id});
    return id;
  }

  int new_edge(int deb, int fin, int cap) {
    int id = arcs.size();
    int r_id = id + 1;
    arcs.push_back({cap, r_id});
    arcs.push_back({cap, id});
    voisins[deb].push_back({fin, id});
    voisins[fin].push_back({deb, r_id});
    return id;
  }

  void reset_dists() {
    dists = vector<int>(voisins.size(), INFINI);
  }

  void bfs() {
    reset_dists();

    list<pair<int, int>> noeuds;
    noeuds.push_back({source, 0});

    while(!noeuds.empty()) {
      pair<int, int> noeud = noeuds.front();
      noeuds.pop_front();
      
      if(derPasse[noeud.first] == curPasse)
	continue;
      derPasse[noeud.first] = curPasse;

      dists[noeud.first] = noeud.second;

      for(pair<int, int> voisin : voisins[noeud.first]) {
	if(arcs[voisin.second].first != 0) {
	  noeuds.push_back({voisin.first, noeud.second + 1});
	}
      }
    }
  }

  int ameliore(int noeud, int flot = INFINI) {
    if(derPasse[noeud] == curPasse)
      return 0;
    derPasse[noeud] = curPasse;

    if(noeud == puits) {
      return flot;
    }

    for(pair<int, int> voisin : voisins[noeud]) {
      if(arcs[voisin.second].first != 0 && dists[voisin.first] == dists[noeud] + 1) {
	int ajout = ameliore(voisin.first, min(flot, arcs[voisin.second].first));
	if(ajout != 0) {
	  arcs[voisin.second].first -= ajout;
	  arcs[arcs[voisin.second].second].first += ajout;
	  return ajout;
	}
      }
    }
    return 0;
  }

  int flot() {
    int reponse = 0;
    while(true) {
      curPasse++;
      bfs();
      
      if(dists[puits] == INFINI) break;
      
      while(true) {
	curPasse++;
	int ajout = ameliore(source);
	
	if(ajout == 0) break;
	reponse += ajout;
      }
    }
    return reponse;
  }
};



int main() {
  ios_base::sync_with_stdio(false);
  int nbTests;
  cin >> nbTests;

  for(int iTest = 0;iTest < nbTests;iTest++) {
    int nbVilles, nbRoutes, maxDiff;
    cin >> nbVilles >> nbRoutes >> maxDiff;

    Graph g;

    vector<int> deg(nbVilles, 0);

    vector<int> ids_villes;
    for(int iVille = 0;iVille < nbVilles;iVille++) {
      ids_villes.push_back(g.new_node());
    }

    vector<vector<pair<int, int>>> arcs(nbVilles);
    vector<int> reponses(nbRoutes, 0);
    
    int needed_flow = 0;
    for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
      int deb, fin;
      cin >> deb >> fin;
      
      deb--;
      fin--;

      int node = g.new_node();
      g.new_directed_edge(node, g.puits, 1);
      int arcDeb = g.new_directed_edge(ids_villes[deb], node, 1);
      int arcFin = g.new_directed_edge(ids_villes[fin], node, 1);

      arcs[deb].push_back({arcDeb, iRoute});
      arcs[fin].push_back({arcFin, iRoute});
      
      deg[deb]++;
      deg[fin]++;

      if(deg[deb] > maxDiff) {
	g.new_directed_edge(g.source, ids_villes[deb], 2);
	needed_flow += 2;
	deg[deb]--;
      }
      if(deg[fin] > maxDiff) {
	g.new_directed_edge(g.source, ids_villes[fin], 2);
	needed_flow += 2;
	deg[fin]--;
      }
    }

    if(g.flot() != needed_flow) {
      for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
	cout << 0 << " ";
      }
    }
    else {
      int nbCompanies = 1;
      for(int iVille = 0;iVille < nbVilles;iVille++) {
	int mod = 0;
	for(pair<int, int> arc : arcs[iVille]) {
	  if(g.arcs[arc.first].first == 0) {
	    reponses[arc.second] = nbCompanies;
	    mod++;
	    if(mod % 2 == 0) {
	      nbCompanies++;
	    }
	  }
	}
      }

      for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
	if(reponses[iRoute] == 0) {
	  reponses[iRoute] = nbCompanies++;
	}
	cout << reponses[iRoute] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}