#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 100005;

/* Tsentroidipuu implementatsioon. adj on sisend, vljundiks on 
 * centroid_children (kus centroid_children[u] on vektor, mis
 * sisaldab kiki tipu u lapsi tsentroidipuus) ning centroid_root,
 * mis on tekkiva tsentroidipuu juurtipp. */
vector<int> adj [MAX_V];
vector<int> centroid_children [MAX_V];
int centroid_root;

int parent [MAX_V]; /* siia kirjutame tipu u vanema algses puus --- nii on mugavam */
void calculate_parents (int vertex, int par) {
  parent[vertex] = par;
  
  for (int nxt : adj[vertex]) {
    if (nxt != par) {
      calculate_parents(nxt, vertex);
    }
  }
}

bool deleted [MAX_V];
int subtree_size [MAX_V];
void calculate_sizes (int vertex) {
  subtree_size[vertex] = 1;
  for (int nxt : adj[vertex]) {
    if (nxt != parent[vertex] && !deleted[nxt]) {
      calculate_sizes(nxt);
      subtree_size[vertex] += subtree_size[nxt];
    }
  }
}

int find_centroid (int vertex) {
  calculate_sizes(vertex);
  int tree_size = subtree_size[vertex];
  
  int cur = vertex;
  while (true) {
    int big_child = -1, big_size = -1;
    for (int nxt : adj[cur]) {
      if (nxt != parent[cur] && !deleted[nxt]) {
	if (subtree_size[nxt] > big_size) {
	  big_size = subtree_size[nxt];
	  big_child = nxt;
	}
      }
    }
    
    /* miks mind siin ei huvita "vanema suunas" olev puu? */
    if (big_size <= tree_size / 2) {
      return cur;
    } else {
      cur = big_child;
    }
  }
}

void decompose (int root, int centroid_parent) {
  int centroid = find_centroid(root);
  deleted[centroid] = true;
  if (centroid_parent == -1) {
    centroid_root = centroid;
  } else {
    centroid_children[centroid_parent].push_back(centroid);
  }

  for (int nxt : adj[centroid]) {
    if (!deleted[nxt] && nxt != parent[centroid]) {
      decompose(nxt, centroid);
    }
  }

  if (!deleted[root]) {
    decompose(root, centroid);
  }
}

void build_centroid_tree () {
  calculate_parents(1, -1);
  decompose(1, -1);
}

/* Siit algab tegelik lesande lahendus. Muidugi oleks vinud auastmed
 * kohe dekomposeerimise kigus ra arvutada, aga nii on modulaarsem ning
 * piirid selgemad. */

char soldier_rank [MAX_V];

void assign_ranks (int vertex, char gets_rank) {
  soldier_rank[vertex] = gets_rank;
  
  for (int child : centroid_children[vertex]) {
    assign_ranks(child, gets_rank + 1);
  }
}

int main () {
  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  build_centroid_tree();
  assign_ranks(centroid_root, 'A');
  
  for (int i = 1; i <= vertexc; i++) {
    cout << soldier_rank[i] << " ";
  }
  cout << endl;
}