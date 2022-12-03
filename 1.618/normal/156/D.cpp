/*


Q.E.D.

result of thinking: Pure.

start coding: 11:36
AC: 

WA: =1. 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
int n, m, k, siz;
vector<int> adj[maxn];
bool vis[maxn];

void dfs(int u) {
  vis[u] = true;
  siz++;
  for (auto v : adj[u]) {
    if (!vis[v])
      dfs(v);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 1, num = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      siz = 0;
      dfs(i);
      ans = (ll)ans * siz % k;
      num++;
    }
  }
  if (num == 1) {
    printf("%d\n", 1 % k);
    return 0;
  }
  for (int i = 1; i <= num - 2; i++)
    ans = (ll)ans * n % k;
  printf("%d\n", ans);
  return 0;
}