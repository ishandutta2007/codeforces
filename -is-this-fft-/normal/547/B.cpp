#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
int locked [MAX_N];

int root [MAX_N];
int sz [MAX_N];
int max_gr;

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  if (u == v) return;
  root[u] = v;
  sz[v] += sz[u];
}


void unlock (int idx) {
  locked[idx] = 0;
  if (!locked[idx - 1]) {
    merge(idx - 1, idx);
  }
  if (!locked[idx + 1]) {
    merge(idx, idx + 1);
  }
  max_gr = max(max_gr, sz[find(idx)]);
}

int ans [MAX_N];

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
    sz[i] = 1;
  }
  
  int n;
  cin >> n;

  vector<pair<int, int>> elems;

  locked[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    locked[i] = 1;
    elems.push_back(make_pair(arr[i], i));
  }
  locked[n + 1] = 1;

  sort(elems.begin(), elems.end(), greater<pair<int, int>>());

  for (auto pr : elems) {
    unlock(pr.second);
    ans[max_gr] = max(ans[max_gr], pr.first);
  }

  for (int i = n - 1; i >= 1; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}