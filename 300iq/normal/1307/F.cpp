#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
 
/*
#pragma GCC optimize("Ofast") //  ,   
#pragma GCC optimize("no-stack-protector") //
#pragma GCC optimize("unroll-loops") //      100         100    
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native") //      03 02        
#pragma GCC optimize("fast-math") //      float   
*/
 
using namespace std;
 
typedef long long ll;
 
#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e5 + 7;
const int K = 20;
 
vector <int> g[N];
 
vector <int> ord;
 
int id[N];
int up[N][K];
int dep[N];
int tin[N], tout[N];
int park[N];
 
int tt = 0;
 
int sok[N];
 
vector <int> pth[N];
int path_id[N];
int id_in_path[N];
 
int orz = 0;
 
void dfs(int v, int pr) {
  tin[v] = tt++;
  id[v] = (int) ord.size();
  up[v][0] = pr;
  for (int i = 1; i < K; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  ord.push_back(v);
  int x = -1;
  for (int to : g[v]) {
    if (to == pr) continue;
    park[to]= v;
    dep[to] = dep[v] + 1;
    dfs(to, v);
    if (x == -1 || sok[to] > sok[x]) {
      x = to;
    }
    sok[v] = max(sok[v], sok[to] + 1);
    ord.push_back(v);
  }
  if (x == -1) {
    path_id[v] = orz++;
  } else {
    path_id[v] = path_id[x];
  }
  id_in_path[v] = pth[path_id[v]].size();
  pth[path_id[v]].push_back(v);
  tout[v] = tt++;
}
 
pair <int, int> spt[2 * N][K];
int lg[2 * N];
 
bool par(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}
 
int lca(int a, int b) {
  int l = id[a];
  int r = id[b];
  if (l > r) swap(l, r);
  int k = lg[r - l + 1];
  return min(spt[l][k], spt[r - (1 << k) + 1][k]).second;
}
 
int dist(int a, int b) {
  return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int mda(int a, int b) {
  return dist(a, b);
}
 
int get_kth(int a, int k) {
  int cur = lg[k];
  a = up[a][cur];
  int need = k - (1 << cur);
  return pth[path_id[a]][id_in_path[a] + need];
}
 
int get_vertex(int a, int b, int x) {
  int c = lca(a, b);
  if (dep[a] - dep[c] >= x) {
    return get_kth(a, x);
  } else {
    int need = x - (dep[a] - dep[c]);
    return get_kth(b, (dep[b] - dep[c]) - need);
  }
}
 
pair <int, int> intersect(pair <int, int> c1, pair <int, int> c2) {
  if (c1.second == -1 || c2.second == -1) {
    return {0, -1};
  }
  int d = dist(c1.first, c2.first);
  if (d > c1.second + c2.second) {
    return {0, -1};
  } else {
    if (c1.second >= c2.second + d) {
      return c2;
    }
    if (c2.second >= c1.second + d) {
      return c1;
    }
    int x = (d + c1.second - c2.second) / 2;
    return {get_vertex(c1.first, c2.first, x), c1.second - x};
  }
}
 
void add_edge(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}
 
int sz[N];
bool die[N];
 
void calc_sz(int v, int pr) {
  sz[v] = 1;
  for (int to : g[v]) {
    if (to != pr && !die[to]) {
      calc_sz(to, v);
      sz[v] += sz[to];
    }
  }
}
 
int find_centroid(int v, int pr, int need) {
  for (int to : g[v]) {
    if (to != pr && !die[to] && sz[to] > need) {
      return find_centroid(to, v, need);
    }
  }
  return v;
}
 
vector <int> st[N], undo[N];
bool real[N];
int ok[N][K];
int lvl[N];
int marked_id[N];
 
int zz = 0;
 
void calc(int v, vector <int> &ds, int lg, int pr = -1, int dist = 0) {
  if (lg != -1) {
    ok[v][lg] = dist;
  } else {
    marked_id[v] = zz;
  }
  if (real[v]) {
    ds.push_back(dist);
  }
  for (int to : g[v]) {
    if (to != pr && !die[to]) {
      calc(to, ds, lg, v, dist + 1);
    }
  }
}
 
int dad[N];
 
void centroid(int useless_vertex, int par = -1, int lg = 0) {
  calc_sz(useless_vertex, -1);
  int v = find_centroid(useless_vertex, -1, sz[useless_vertex] / 2);
  calc(v, st[v], lg);
  dad[v] = par;
  lvl[v] = lg;
  auto mda = st[v];
  st[v].clear();
  for (int x : mda) {
    if (st[v].size() <= x) st[v].resize(x + 1);
    st[v][x]++;
  }
  for (int i = 1; i < (int) st[v].size(); i++) {
    st[v][i] += st[v][i - 1];
  }
  for (int to : g[v]) {
    if (!die[to]) {
      calc(to, undo[zz], -1, v, 1);
      mda = undo[zz];
      undo[zz].clear();
      for (int x : mda) {
        if (undo[zz].size() <= x) undo[zz].resize(x + 1);
        undo[zz][x]++;
      }
      for (int i = 1; i < (int) undo[zz].size(); i++) {
        undo[zz][i] += undo[zz][i - 1];
      }
      zz++;
    }
  }
  die[v] = true;
  for (int to : g[v]) {
    if (!die[to]) {
      centroid(to, v, lg + 1);
    }
  }
}
 
int bsearch(vector <int> &arr, int x) {
  if (x < 0 || arr.empty()) return 0;
  x = min(x, (int) arr.size() - 1);
  return arr[x];
}
 
int calc(int v, int x) {
  int prv = -1;
  int ans = 0;
  int cur = v;
  while (v != -1) {
    int need = x - ok[cur][lvl[v]];
    ans += bsearch(st[v], need);
    if (prv != -1) {
      ans -= bsearch(undo[marked_id[prv]], need);
    }
    prv = v;
    v = dad[v];
  }
  return ans;
}
 
int cost(pair <int, int> p) {
  if (p.second == -1) {
    return 0;
  } else {
    return calc(p.first, p.second);
  }
}
 
struct triple {
  int l, r, t;
};
 
const int B = 200;
const int inf = 1e9;
 
 
int ans[N];
int here[N];
 
pair <int, int> rt[N];

int dsu[N];

int get(int v) {
  if (v == dsu[v]) {
    return v;
  } else {
    return dsu[v] = get(dsu[v]);
  }
}

void uni(int u, int v) {
  dsu[get(u)] = get(v);
}

vector <int> rofl[N];
int okk[N];

bitset <N / B + 123> prec[N];
 
int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, r;
  cin >> n >> k >> r;
  int sz = n;
  for (int i = 0; i < n; i++) {
    real[i] = true;
  }
  for (int i= 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    add_edge(a, b);
  }
  vector <int> v(r);
  vector <int> dist(n, -1);
  vector <int> who(n, -1);
  queue <int> q;
  for (int i = 0; i < r; i++) {
    cin >> v[i];
    v[i]--;
    dist[v[i]] = 0;
    dsu[v[i]] = v[i];
    who[v[i]] = v[i];
    q.push(v[i]);
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int to : g[v]) {
      if (dist[to] == -1) {
        dist[to] = dist[v] + 1;
        who[to] = who[v];
        q.push(to);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      if (who[i] != who[j] && dist[i] + 1 + dist[j] <= k) {
        uni(who[i], who[j]);
      }
    }
  }
   dfs(0, 0);
  for (int i = 0; i < orz; i++) {
    int len = (int) pth[i].size() + 10;
    int v = pth[i].back();
    while (len--) {
      v = park[v];
      if (v == -1) break;
      pth[i].push_back(v);
    }
  }
  //centroid(0);
  for (int i= (int) ord.size() - 1; i >= 0; i--) {
    for (int j = 0; i + (1 << j) - 1 < (int) ord.size(); j++) {
      if (j == 0) {
        spt[i][j] = make_pair(dep[ord[i]], ord[i]);
      } else {
        spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  lg[1] = 0;
  for (int i = 2; i < (int) ord.size(); i++) {
    lg[i] = lg[i / 2] + 1;
  }
  set <int> md;
  for (int x : v) {
    rofl[get(x)].push_back(x);
    md.insert(get(x));
  }
  int id = 0;
  for (int t : md) {
    if (rofl[t].size() >= B) {
      queue <int> q;
      for (int i = 0; i < n; i++) {
        okk[i] = -1;
      }
      for (int mda : rofl[t]) {
        q.push(mda);
        okk[mda] = 0;
      }
      while (!q.empty()) {
        int v= q.front();
        q.pop();
        if (okk[v] > k) {
          break;
        }
        for (int to : g[v]) {
          if (okk[to] == -1) {
            okk[to] = okk[v] + 1;
            q.push(to);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (okk[i] <= k && okk[i] != -1) {
          prec[i][id] = 1;
        }
      }
      id++;
    }
  }
  int qr;
  cin >> qr;
  while (qr--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    int dist = mda(a, b);
    if (dist <= k || (prec[a] & prec[b]).count()) {
      cout << "YES\n";
      continue;
    }
    int vert = get_vertex(a, b, dist / 2);
    int cl = get(who[vert]);
    bool l = false, r = false;
    if (rofl[cl].size() < B) {
      for (int x : rofl[cl]) {
        if (!l && mda(a, x) <= k) {
          l = true;
        }
        if (!r && mda(b, x) <= k) {
          r = true;
        }
      }
    }
    if (l && r) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}