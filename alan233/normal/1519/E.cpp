// xyr2005 txdy!
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 500005;

map<pair<ll, ll>, int> mapID; int ID_tot;
int getID(ll x, ll y) {
  ll g = __gcd(x, y); x /= g, y /= g;
  if (!mapID.count({x, y})) mapID[{x, y}] = ++ID_tot;
  return mapID[{x, y}]; 
} 

struct Edge {
  int to, nxt, tag;
} edge[N << 1];
int head[N], tot;
void add(int u, int v, int tag) {
  edge[++tot] = {v, head[u], tag};
  head[u] = tot;
}

int dep[N], vis[N], n;
vector<pii> ans;
bool dfs1(int u, int fa) {
  if (vis[u]) return 0;
  dep[u] = dep[fa] + 1;
  vis[u] = 1;
  int f = 0;
  auto ins = [&](int x) {
    if (!f) f = x;
    else ans.pb({f, x}), f = 0;
  };
  int dad = 0;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (!vis[v]) {
      if (dfs1(v, u)) ins(edge[i].tag); 
    } else {
      if (!dad && v == fa) dad = edge[i].tag;
      else if (dep[v] < dep[u]) ins(edge[i].tag);
    }
  }
  if (dad && f) {
    ins(dad);
    return 0;
  } else { //  dad 
    return 1;
  }
}

int main() {
  n = read();
  rep(i, 1, n) {
    ll a = read(), b = read(), c = read(), d = read();
    int t1 = getID(b * c, d * (a + b)), t2 = getID(b * (c + d), a * d);
    add(t1, t2, i), add(t2, t1, i);
  }
  rep(i, 1, ID_tot) dfs1(i, 0);
  print(SZ(ans), '\n');
  for (auto v: ans) print(v.fir, ' '), print(v.sec, '\n');
  return 0;
}