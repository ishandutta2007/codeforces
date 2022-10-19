#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int spf[N];

vector<int> k[N]; // prime -> list of i for which p divides a[i]
unordered_set<int> nbrs[150005]; // root -> other roots it can connect to

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

vector<int> pfact(int m) {
  vector<int> ans;
  while (m != 1) {
    int p = spf[m];
    ans.push_back(p);
    while (m % p == 0) m /= p;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(spf, spf+N, 0);
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = 2*i; j < N; j+=i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  dsu d(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int p: pfact(a[i])) {
      k[p].push_back(i);
    }
  }
  
  for (int p = 2; p < N; p++) {
    if (k[p].size()) {
      int m = k[p].size();
      for (int j = 0; j < m-1; j++) {
        d.join(k[p][j], k[p][j+1]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    int r = d.root(i);
    vector<int> other;
    for (int p: pfact(a[i]+1)) {
      if (k[p].size()) {
        int b = d.root(k[p][0]);
        other.push_back(b);
      }
    }
    sort(other.begin(), other.end());
    other.resize(unique(other.begin(), other.end())-other.begin());
    for (int s: other) {
      nbrs[r].insert(s);
      nbrs[s].insert(r);
    }
    for (int s: other) {
      for (int q: other) {
        nbrs[s].insert(q);
        nbrs[q].insert(s);
      }
    }
  }

  while (q--) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    int a = d.root(s);
    int b = d.root(t);
    if (a == b) {
      cout << "0\n";
    }
    else if (nbrs[a].count(b)) {
      cout << "1\n";
    }
    else {
      cout << "2\n";
    }
  }
}