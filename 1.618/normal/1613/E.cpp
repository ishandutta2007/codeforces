/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 1000005
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, lab, deg[maxn];
string s[maxn];
vector<int> adj[maxn];
bool ans[maxn];

void solve() {
  memset(ans, 0, sizeof(ans));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n * m; i++)
    adj[i].clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#')
        continue;
      if (s[i][j] == 'L')
        lab = i * m + j;
      for (int d = 0; d < 4; d++) {
        int cx = i + dx[d], cy = j + dy[d];
        if (cx >= 0 && cx < n && cy >= 0 && cy < m && s[cx][cy] != '#') {
          adj[i * m + j].push_back(cx * m + cy);
        }
      }
      deg[i * m + j] = adj[i * m + j].size();
    }
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << deg[i * m + j] << " ";
  //   }
  //   cout << endl;
  // }
  // system("pause");

  queue<int> que;
  que.push(lab);
  while (!que.empty()) {
    int u = que.front();
    ans[u] = true;
    que.pop();
    for (auto v : adj[u]) {
      deg[v]--;
      if (!ans[v] && deg[v] <= 1)
        que.push(v);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.' && ans[i * m + j])
        s[i][j] = '+';
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}