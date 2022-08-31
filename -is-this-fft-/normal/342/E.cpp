#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX_V = 100005;

/* Tsentroidipuu implementatsioon. adj on sisend, vljundiks on 
 * centroid_children (kus centroid_children[u] on vektor, mis
 * sisaldab kiki tipu u lapsi tsentroidipuus) ning centroid_root,
 * mis on tekkiva tsentroidipuu juurtipp. */
vector<int> adj [MAX_V];
vector<int> centroid_children [MAX_V];
int centroid_parent [MAX_V];
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

void decompose (int root, int centroid_par) {
  int centroid = find_centroid(root);
  deleted[centroid] = true;
  if (centroid_par == -1) {
    centroid_root = centroid;
  } else {
    centroid_children[centroid_par].push_back(centroid);
  }
  centroid_parent[centroid] = centroid_par;

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
  calculate_parents(1, 0);
  decompose(1, -1);
}

/* Siit algab tegelik lesande lahendus. */

const int MAX_LG = 20;
int lvl [MAX_V];
int jump [MAX_V][MAX_LG];

void build_lca (int vertex) {
  lvl[vertex] = lvl[parent[vertex]] + 1;
  jump[vertex][0] = parent[vertex];
  for (int i = 1; i < MAX_LG; i++) {
    jump[vertex][i] = jump[jump[vertex][i - 1]][i - 1];
  }

  for (int nxt : adj[vertex]) {
    if (nxt != parent[vertex]) {
      build_lca(nxt);
    }
  }
}

int lca (int u, int v) {
  if (lvl[u] < lvl[v]) {
    swap(u, v);
  }

  int diff = lvl[u] - lvl[v];
  for (int i = 0; i < MAX_LG; i++) {
    if (diff & 1 << i) {
      u = jump[u][i];
    }
  }

  if (u == v) {
    return u;
  }

  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (jump[u][i] != jump[v][i]) {
      u = jump[u][i];
      v = jump[v][i];
    }
  }

  return jump[u][0];
}

int dist (int u, int v) {
  int lc = lca(u, v);
  return lvl[u] - lvl[lc] + lvl[v] - lvl[lc];
}

int ans [MAX_V];

void paint (int u) {
  for (int cur = u; cur != -1; cur = centroid_parent[cur]) {
    ans[cur] = min(ans[cur], dist(u, cur));
  }
}

int query (int u) {
  int resp = MAX_V;
  for (int cur = u; cur != -1; cur = centroid_parent[cur]) {
    resp = min(resp, ans[cur] + dist(u, cur));
  }
  return resp;
}

int main () {
  for (int i = 0; i < MAX_V; i++) {
    ans[i] = MAX_V;
  }

  int vertexc, queryc;
  cin >> vertexc >> queryc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  build_centroid_tree();
  build_lca(1);
  
  paint(1);
  for (int i = 0; i < queryc; i++) {
    int type, arg;
    cin >> type >> arg;

    if (type == 1) {
      paint(arg);
    } else {
      cout << query(arg) << '\n';
    }
  }
}