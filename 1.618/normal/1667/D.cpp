/*
start thinking:
BULB:
result of thinking: Pure.

,  44 , *2900, .
, . , .
 dp? , .
? 
,  dp ?
 2 (,  1), , 
, >= 3 .
, ?
#

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
int n;
vector<P> adj[maxn]; // to, id.
P el[maxn];
int nxt[maxn];
vector<int> ans;

void dfs(int u, int f) {
  vector<int> foo[2];
  for (auto e : adj[u]) {
    if (e.second == f)
      continue;
    dfs(e.first, e.second);
    foo[(adj[u].size() ^ !nxt[e.second]) & 1].push_back(e.second);
  }
  int i;
  for (i = 0; ; i ^= 1) {
    if (foo[i].empty())
      break;
    for (int j = foo[i].back(); j; j = nxt[j]) {
      ans.push_back(j);
    }
    foo[i].pop_back();
  }
  i ^= 1;
  if (foo[i].size())
    nxt[f] = foo[i][0];
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    adj[i].clear();
  for (int i = 0; i < n; i++)
    nxt[i] = 0;
  ans.clear();
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &el[i].first, &el[i].second);
    adj[el[i].first].push_back({el[i].second, i});
    adj[el[i].second].push_back({el[i].first, i});
  }
  dfs(1, 0);
  if ((int)ans.size() < n - 1) {
    puts("NO");
    return;
  }
  puts("YES");
  for (auto i : ans) {
    printf("%d %d\n", el[i].first, el[i].second);
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}