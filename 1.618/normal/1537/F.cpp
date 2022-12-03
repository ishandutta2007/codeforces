/*


Q.E.D.

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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 200005
int n, m, s[maxn], t[maxn], col[maxn];
ll sum, sum1, sum2;
vector<int> adj[maxn];

bool dfs(int u, int c) {
  col[u] = c;
  for (auto v : adj[u]) {
    if (!col[v]) {
      if (!dfs(v, -c))
        return false;
    } else if (col[v] == c) {
      return false;
    }
  }
  return true;
}

void solve() {
  scanf("%d%d", &n, &m);
  sum = sum1 = sum2 = 0;
  for (int i = 1; i <= n; i++) {
    col[i] = 0;
    adj[i].clear();
  }
  for (int i = 1; i <= n; i++)
    scanf("%d", s + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", t + i);
    sum += s[i] - t[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (sum & 1) {
    puts("NO");
    return;
  }
  bool bip = dfs(1, 1);
  if (!bip) {
    puts("YES");
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (col[i] == 1)
      sum1 += s[i] - t[i];
    else
      sum2 += s[i] - t[i];
  }
  puts(sum1 == sum2 ? "YES" : "NO");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}