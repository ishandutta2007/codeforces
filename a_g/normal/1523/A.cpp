#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> d(n, INF);
    vector<int> que;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        d[i] = 0;
        que.push_back(i);
      }
    }

    for (int i = 0; i < (int)que.size(); i++) {
      int v = que[i];
      if (v > 0 && d[v-1] == INF) {
        d[v-1] = d[v]+1;
        que.push_back(v-1);
      }
      if (v+1 < n && d[v+1] == INF) {
        d[v+1] = d[v]+1;
        que.push_back(v+1);
      }
    }

    for (int i = 0; i < n; i++) {
      cout << (d[i] <= m && (i == 0 || i == n-1 || d[i] != max(d[i-1], d[i+1])+1) ? '1' : '0');
    }
    cout << '\n';
  }
}