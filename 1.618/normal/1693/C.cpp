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
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int dis[maxn], n, m, deg[maxn];
vector<int> radj[maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    radj[v].push_back(u);
    deg[u]++;
  }
  memset(dis, 0x3f, sizeof(dis));
  dis[n] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push({0, n});
  while (!que.empty()) {
    auto p = que.top();
    que.pop();
    int u = p.second;
    if (p.first != dis[u])
      continue;
    for (auto v : radj[u]) {
      deg[v]--;
      if (chmin(dis[v], dis[u] + 1 + deg[v])) {
        que.push({dis[v], v});
      }
    }
  }
  printf("%d\n", dis[1]);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}