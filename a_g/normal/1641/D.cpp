#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int B = 250;
const int INF = 2e9+1e6;
bitset<N> M[5*(N/B+1)];
vector<int> occ[5*N];
int big[5*N];
int ptr = 1;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, vector<int>>> a(n);
  vector<int> vals;
  for (int i = 0; i < n; i++) {
    a[i].second.resize(m);
    for (int j = 0; j < m; j++) {
      int val;
      cin >> val;
      a[i].second[j] = val;
      vals.push_back(val);
    }
    cin >> a[i].first;
  }
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end())-vals.begin());
  auto compress = [&] (int x) {return lower_bound(vals.begin(), vals.end(), x) - vals.begin();};
  sort(a.begin(), a.end());
  for (pair<int, vector<int>>& p: a) {
    for (int& val: p.second) {
      val = compress(val);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int val: a[i].second) {
      occ[val].push_back(i);
    }
  }

  for (int i = 0; i < 5*N; i++) {
    if (occ[i].size() > B) {
      big[i] = ptr++;
      for (int j: occ[i]) {
        M[big[i]][j] = 1;
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < n; i++) {
    bitset<N> bad = 0;
    for (int val: a[i].second) {
      if (big[val]) bad |= M[big[val]];
      else {
        for (int j: occ[val]) {
          bad[j] = 1;
        }
      }
    }
    bad.flip();
    int j = bad._Find_first();
    if (j < n) {
      ans = min(ans, a[i].first+a[j].first);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';
}