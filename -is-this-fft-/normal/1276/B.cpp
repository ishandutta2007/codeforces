#include <iostream>
#include <vector>

using namespace std;

#define u first
#define v second

const int MAX_N = 2e5 + 5;

int root [MAX_N];
int nbs [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

void solve () {
  int vertexc, edgec, A, B;
  cin >> vertexc >> edgec >> A >> B;

  for (int i = 1; i <= vertexc; i++) {
    root[i] = i;
    nbs[i] = 0;
  }

  vector<pair<int, int>> edges (edgec);
  for (int i = 0; i < edgec; i++) {
    cin >> edges[i].first >> edges[i].second;
  }

  for (auto pr : edges) {
    if (pr.u != A && pr.u != B && pr.v != A && pr.v != B) {
      merge(pr.u, pr.v);
    }
  }

  for (auto pr : edges) {
    if ((pr.u == A || pr.v == A) && pr.u != B && pr.v != B) {
      int oth = pr.u ^ pr.v ^ A;
      nbs[find(oth)] |= 1;
    }

    if ((pr.u == B || pr.v == B) && pr.u != A && pr.v != A) {
      int oth = pr.u ^ pr.v ^ B;
      nbs[find(oth)] |= 2;
    }
  }

  int ac = 0, bc = 0;
  for (int i = 1; i <= vertexc; i++) {
    if (nbs[find(i)] == 1) ac++;
    if (nbs[find(i)] == 2) bc++;
  }

  cout << (long long) ac * (long long) bc << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i =0 ; i < testc; i++) {
    solve();
  }
}