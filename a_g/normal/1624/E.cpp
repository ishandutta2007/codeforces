#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    map<string, tuple<int, int, int>> lookup;
    for (int i = 1; i <= n; i++) {
      string p;
      cin >> p;
      for (int j = 0; j < m-1; j++) {
        lookup[p.substr(j, 2)] = {j+1, j+2, i};
      }
      for (int j = 0; j < m-2; j++) {
        lookup[p.substr(j, 3)] = {j+1, j+3, i};
      }
    }
    string s;
    cin >> s;
    vector<int> prv(m+1, -1);
    prv[0] = 0;
    for (int i = 0; i < m-1; i++) {
      if (prv[i] == -1) continue;
      if (i < m-1) {
        if (lookup.count(s.substr(i, 2))) {
          prv[i+2] = i;
        }
      }
      if (i < m-2) {
        if (lookup.count(s.substr(i, 3))) {
          prv[i+3] = i;
        }
      }
    }
    if (prv[m] == -1) {
      cout << "-1\n";
      continue;
    }
    vector<tuple<int, int, int>> ans;
    int curr = m;
    while (curr) {
      int k = curr-prv[curr];
      curr = prv[curr];
      ans.push_back(lookup[s.substr(curr, k)]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (tuple<int, int, int> t: ans) {
      cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
    }
  }
}