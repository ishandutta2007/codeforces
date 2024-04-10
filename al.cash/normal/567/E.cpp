#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 1e12;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* separator = " ", const char* closing = "\n") {
  for (Iterator it = begin; it != end; printf(fmt, *it),
       printf("%s", ++it == end ? closing : separator));
}

const int N = 1e5+5;
int n, m, s, t;
vector<pii> g[N], r[N];
ll dg[N], dr[N];

void Dijkstra(int s, vector<pii>* e, ll* d) {
  REP(i, n+1) d[i] = INF_LL;
  d[s] = 0;
  priority_queue<pair<ll, int>> q;
  q.emplace(0, s);
  while (!q.empty()) {
    auto pv = q.top();
    q.pop();
    int v = pv.Y;
    if (d[v] != -pv.X) continue;
    for (auto i : e[v]) {
      int u = i.X;
      ll du = d[v] + i.Y;
      if (du < d[u]) {
        d[u] = du;
        q.emplace(-du, u);
      }
    }
  }
}

ll ans;
set<pii> y;

struct {
  int a, b, l;

  void inp() {
    scanf("%d%d%d", &a, &b, &l);
    g[a].eb(b, l);
    r[b].eb(a, l);
  }
  
  void outp() {
    ll s = dg[a] + l + dr[b] - ans;
    if (s == 0 && y.count({a, b})) {
      printf("YES\n");
    } else {
      ++s;
      if (s < l) printf("CAN %d\n", int(s));
      else printf("NO\n");
    }
  }
} e[N];

bool f[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  
  scanf("%d%d%d%d", &n, &m, &s, &t);
  REP(i, m) e[i].inp();
  Dijkstra(s, g, dg);
  Dijkstra(t, r, dr);
  ans = dg[t];
  priority_queue<pair<ll, int>> q;
  q.emplace(0, s);
  f[s] = true;
  while (!q.empty()) {
    auto pv = q.top();
    q.pop();
    int v = pv.Y;
    if (v == t) break;
    int z = q.empty() ? -1 : -2;
    for (auto i : g[v]) {
      int u = i.X;
      if (dg[v] + i.Y + dr[u] == ans) {
        if (z == -1) z = u;
        else z = -2;
        if (!f[u]) {
          q.emplace(-dg[u], u);
          f[u] = true;
        }
      }
    }
    if (z >= 0) y.insert({v, z});
  }
  REP(i, m) e[i].outp();
  
#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}