#include <iostream>
#include <vector>

const int MAX_VERT = 100005;
const int MODULUS = 1000000007;

using namespace std;

struct edge {
  int endp, love;

  edge () {
    endp = 0;
    love = 0;
  }

  edge (int ie, int il) {
    endp = ie;
    love = il;
  }
};

long long fast_exp (long long base, int exponent) {
  long long powers [30];
 
  powers[0] = base;
  for (int i = 1; i < 30; i++) {
    powers[i] = (powers[i - 1] * powers[i - 1]) % MODULUS;
  }

  long long ans = 1;
  for (int i = 0; i < 30; i++) {
    if (exponent & 1 << i) {
      ans *= powers[i];
      ans %= MODULUS;
    }
  }

  return ans;
}

vector<edge> adj [MAX_VERT];
int comp_id [MAX_VERT], partite_id [MAX_VERT];

void traverse (int vertex, int comp, int part) {
  comp_id[vertex] = comp;
  partite_id[vertex] = part;

  for (int i = 0; i < adj[vertex].size(); i++) {
    if (comp_id[adj[vertex][i].endp] == 0) {
      if (adj[vertex][i].love == 1) {
	traverse(adj[vertex][i].endp, comp, part);
      } else {
	traverse(adj[vertex][i].endp, comp, -part);
      }
    }
  }
}

int main () {
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v, love;
    cin >> u >> v >> love;

    adj[u].push_back(edge(v, love));
    adj[v].push_back(edge(u, love));
  }

  int compc = 0;
  for (int i = 1; i <= vertexc; i++) {
    if (comp_id[i] == 0) {
      compc++;
      traverse(i, compc, 1);
    }
  }

  bool ok = true;
  for (int i = 1; i <= vertexc; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      if (adj[i][j].love == 1) {
	ok &= (partite_id[i] == partite_id[adj[i][j].endp]);
      } else {
	ok &= (partite_id[i] != partite_id[adj[i][j].endp]);
      }
    }
  }

  if (ok) {
    cout << fast_exp(2, compc - 1) << endl; /* Black magic */
  } else {
    cout << 0 << endl;
  }
}