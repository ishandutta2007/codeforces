#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define u first
#define v second

const int MAX_N = 3e5 + 5;
const int MAX_Q = 5e5 + 5;

int arr [MAX_N];
pair<int, int> E [MAX_N];
pair<int, int> qs [MAX_Q];

int root [MAX_N];
vector<int> children [MAX_N];


int bec_ind [MAX_Q];

void merge (int u, int v, int T) {
  u = root[u];
  v = root[v];

  if (u == v) return;
  if ((int) children[u].size() < (int) children[v].size()) {
    swap(u, v);
  }

  if (T != -1) {
    bec_ind[T] = v;
  }
  
  for (int w : children[v]) {
    root[w] = u;
    children[u].push_back(w);
  }
}

set<pair<int, int>> setof [MAX_N];

void find_top (int u) {
  u = root[u];
  pair<int, int> pr = *setof[u].rbegin();
  cout << pr.first << '\n';
  arr[pr.second] = 0;
  setof[u].erase(pr);
  setof[u].insert(make_pair(0, pr.second));
}

void split (int T) {
  int u = bec_ind[T];
  if (u == 0) return;

  int p = root[u];
  for (int w : children[u]) {
    root[w] = u;
    setof[p].erase(make_pair(arr[w], w));
    setof[u].insert(make_pair(arr[w], w));
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, m, qc;
  cin >> n >> m >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> E[i].u >> E[i].v;
  }

  set<int> rem;
  for (int i = 1; i <= qc; i++) {
    cin >> qs[i].first >> qs[i].second;
    if (qs[i].first == 2) {
      rem.insert(qs[i].second);
    }
  }

  for (int i = 1; i <= n; i++) {
    root[i] = i;
    children[i].push_back(i);
  }
  
  for (int i = 1; i <= m; i++) {
    if (!rem.count(i)) {
      merge(E[i].u, E[i].v, -1);
    }
  }

  for (int i = qc; i >= 1; i--) {
    if (qs[i].first == 2) {
      int idx = qs[i].second;
      merge(E[idx].u, E[idx].v, i);
    }
  }
  
  for (int i = 1; i <= n; i++) {
    if (root[i] == i) {
      for (int w : children[i]) {
        setof[i].insert(make_pair(arr[w], w));
      }
    }
  }

  for (int i = 1; i <= qc; i++) {
    if (qs[i].first == 1) {
      find_top(qs[i].second);
    } else {
      split(i);
    }
  }
}