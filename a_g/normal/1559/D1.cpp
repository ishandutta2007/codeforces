#include <bits/stdc++.h>
#define ll long long
using namespace std;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> sizes; //subtree size, maintained at root
    dsu (int n) {
      parents.resize(n);
      for (int i = 0; i < n; i++) {
        parents[i] = i;
      }
      ranks.resize(n, 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      if (parents[u] == u) return u;
      parents[u] = root(parents[u]);
      return parents[u];
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      int size = sizes[a] + sizes[b];
      if (ranks[a] > ranks[b]) swap(a, b);
      // b has higher rank
      parents[a] = b;
      sizes[b] = size;
      if (ranks[a] == ranks[b]) ranks[b]++;
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  cout << n-1-max(m1, m2) << endl;
  dsu mocha(n);
  dsu diana(n);
  int u, v;
  while (m1--) {
    cin >> u >> v;
    mocha.join(u-1, v-1);
  }
  while (m2--) {
    cin >> u >> v;
    diana.join(u-1, v-1);
  }
  queue<int> unjoined_mocha;
  queue<int> unjoined_diana;
  for (int i = 1; i < n; i++) {
    if (mocha.root(i) != mocha.root(0) && diana.root(i) != diana.root(0)) {
      cout << 1 << " " << i+1 << endl;
      mocha.join(0, i);
      diana.join(0, i);
    }
    else if (mocha.root(i) == mocha.root(0)) {
      unjoined_diana.push(i);
    }
    else {
      unjoined_mocha.push(i);
    }
  }
  while (!unjoined_diana.empty() && !unjoined_mocha.empty()) {
    int u = unjoined_mocha.front();
    int v = unjoined_diana.front();
    if (mocha.root(u) == mocha.root(0)) {
      unjoined_mocha.pop();
    }
    else if (diana.root(v) == diana.root(0)) {
      unjoined_diana.pop();
    }
    else {
      cout << u+1 << " " << v+1 << endl;
      mocha.join(u, v);
      diana.join(u, v);
      unjoined_mocha.pop();
      unjoined_diana.pop();
    }
  }
}