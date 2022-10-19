#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

int n, m;
vector<pii> getnbrs(int i, int j) {
  vector<pii> ans;
  if (i > 0) ans.push_back({i-1, j});
  if (i < n-1) ans.push_back({i+1, j});
  if (j > 0) ans.push_back({i, j-1});
  if (j < m-1) ans.push_back({i, j+1});
  return ans;
}

const int maxn = 1002;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> n >> m >> t;
  bool flag = 0;
  bool table[maxn][maxn];
  bool visited[maxn][maxn];
  int times[maxn][maxn];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      table[i][j] = (s[j] == '1');
      visited[i][j] = 0;
    }
  }
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool stable = 0;
      for (pii p: getnbrs(i, j)) {
        if (table[p.first][p.second] == table[i][j]) {
          stable = 1;
        }
      }
      if (stable) {
        times[i][j] = 0;
        q.push({i, j});
        visited[i][j] = 1;
      }
    }
  }
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    for (pii o: getnbrs(p.first, p.second)) {
      if (!visited[o.first][o.second]) {
        visited[o.first][o.second] = 1;
        times[o.first][o.second] = times[p.first][p.second] + 1;
        q.push(o);
      }
    }
  }
  while (t--) {
    int i, j;
    ll p;
    cin >> i >> j >> p;
    i--, j--;
    bool a = table[i][j];
    bool b = (p&1);
    if (!visited[i][j] || p <= times[i][j]) {
      cout << a << '\n';
    }
    else {
      bool c = times[i][j]&1;
      cout <<  (a^b^c) << '\n';
    }
  }
}