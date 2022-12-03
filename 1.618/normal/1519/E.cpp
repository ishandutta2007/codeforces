/*
result of thinking: Pure.
 = 

 
start coding: 17:54
AC:
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

struct Rational {
  ll a, b; // x = a / b;
  void reduce() {
    ll tmp = __gcd(a, b);
    a /= tmp, b /= tmp;
  }
  bool operator == (const Rational &x) const {
    assert(__gcd(a, b) == 1);
    assert(__gcd(x.a, x.b) == 1);
    return a == x.a && b == x.b;
  }
  bool operator < (const Rational &x) const {
    return a * x.b < b * x.a;
  }
  Rational operator / (Rational x) {
    Rational res = (Rational){a * x.b, b * x.a};
    res.reduce();
    return res;
  }
};

#define mp make_pair
typedef pair<int, int> P;
typedef pair<Rational, Rational> Prr;
typedef pair<Rational, int> Pri;
#define maxn 200005
#define maxV 400005
int n;
Prr pts[maxn];
Pri pos[maxV]; // (slope, id).

vector<P> adj[maxV]; // (to, corresponding edge) 
int V, hand[maxn][2], cnt[maxn];
bool vis[maxV], evis[maxn];
vector<int> ans[maxV]; // . 

void dfs(int u, int fid, int f) {
  vis[u] = true;
  for (auto e : adj[u]) {
    if (e.second == fid)
      continue;
    int v = e.first;
    if (!vis[v]) {
      dfs(v, e.second, u);
    } else if (!evis[e.second]) {
      ans[v].push_back(e.second);
      evis[e.second] = true;
    }
  }
  if (fid) {
    if (ans[u].size() & 1) {
      ans[u].push_back(fid);
    } else {
      ans[f].push_back(fid);
    }
    evis[fid] = true;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld%lld%lld", &pts[i].first.a, &pts[i].first.b,
                              &pts[i].second.a, &pts[i].second.b);
    pts[i].first.reduce();
    pts[i].second.reduce();
    pos[i * 2 - 1] = mp(pts[i].second / 
      (Rational){pts[i].first.a + pts[i].first.b, pts[i].first.b}, i);
    pos[i * 2] = mp((Rational){pts[i].second.a + pts[i].second.b, 
      pts[i].second.b} / pts[i].first, i);
  }
  sort(pos + 1, pos + n * 2 + 1);
  for (int i = 1, j; i <= n * 2; i = j) {
    for (j = i; j <= n * 2 && pos[j].first == pos[i].first; j++);
    V++;
    for (int k = i; k < j; k++)
      hand[pos[k].second][cnt[pos[k].second]++] = V;
  }
  for (int i = 1; i <= n; i++) {
    adj[hand[i][0]].push_back(mp(hand[i][1], i));
    adj[hand[i][1]].push_back(mp(hand[i][0], i));
  }
  for (int i = 1; i <= V; i++) {
    if (!vis[i]) {
      dfs(i, 0, 0);
    }
  }
  int c = 0;
  for (int i = 1; i <= V; i++)
    c += ans[i].size() / 2;
  printf("%d\n", c);
  for (int i = 1; i <= V; i++) {
    for (int j = 0; j + 1 < (int)ans[i].size(); j += 2) {
      printf("%d %d\n", ans[i][j], ans[i][j + 1]);
    }
  }
  return 0;
}