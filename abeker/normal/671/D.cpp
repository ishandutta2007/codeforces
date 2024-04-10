#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 300005;
const int offset = 1 << 19;
const ll INF = (ll)1e16;

struct node {
  ll mini, lazy;
  node(ll mini, ll lazy) : mini(mini), lazy(lazy) {}
  node() : mini(INF), lazy(0) {}
};

int N, M;
int u[MAXN], v[MAXN], cost[MAXN];
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
vector <int> start[MAXN];
pii path[MAXN];
int pos[MAXN];
ll dp[MAXN];
node t[2 * offset];
int timer = 1;

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i < N; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  for (int i = 0; i < M; i++) 
    scanf("%d%d%d", u + i, v + i, cost + i);
}

void add(ll &x, ll y) {
  x = min(x + y, INF);
}

node merge(node l, node r) {
  return node(min(l.mini, r.mini), l.lazy + r.lazy);
}

void prop(int x) {
  t[x].mini += t[x].lazy;
  if (x < offset) {
    t[2 * x].lazy += t[x].lazy;
    t[2 * x + 1].lazy += t[x].lazy;
  }
  t[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, ll val) {
  prop(x);
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    t[x].mini += val;
    if (x < offset) {
      t[2 * x].lazy += val;
      t[2 * x + 1].lazy += val;
    }
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, val);
  update(2 * x + 1, mid, hi, from, to, val);
  t[x] = merge(t[2 * x], t[2 * x + 1]);
}

void update(int from, int to, ll val) {
  update(1, 0, offset, from, to, val);
}

node query(int x, int lo, int hi, int from, int to) {
  prop(x);
  if (lo >= to || hi <= from)
    return node();
  if (lo >= from && hi <= to)
    return t[x];
  int mid = (lo + hi) / 2;
  return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

ll query(int from, int to) {
  return query(1, 0, offset, from, to).mini;  
}

void set(int x, ll val) {
  update(x, x + 1, val - query(x, x + 1));
}

int compress(int val) {
  return lower_bound(path, path + M, pii(val, -1)) - path;
}

void modify(int from, int to, ll val) {
  update(compress(from), compress(to), val);
}

ll get(int from, int to) {
  return query(compress(from), compress(to));
}

void dfs(int x, int p) {
  disc[x] = timer++;
  for (int i = 0; i < E[x].size(); i++) 
    if (E[x][i] != p) 
      dfs(E[x][i], x);
  fin[x] = timer;
}

ll go(int x, int p) {
  for (int i = 0; i < start[x].size(); i++) 
    set(pos[start[x][i]], cost[start[x][i]]);
  
  ll tot = 0;
  for (int i = 0; i < E[x].size(); i++)
    if (E[x][i] != p) 
      add(tot, go(E[x][i], x));
      
  for (int i = 0; i < start[x].size(); i++)
    set(pos[start[x][i]], INF);
  
  dp[x] = INF;
  for (int i = 0; i < E[x].size(); i++) {
    int nxt = E[x][i];
    if (nxt == p)
      continue;
    modify(disc[nxt], fin[nxt], tot - dp[nxt]);
    dp[x] = min(dp[x], get(disc[nxt], fin[nxt]));
  }
  modify(disc[x], disc[x] + 1, tot);
  dp[x] = min(dp[x], get(disc[x], disc[x] + 1));
  
  return dp[x];
}

ll solve() {
  dfs(1, 0);  
  
  for (int i = 0; i < M; i++) {
    path[i] = pii(disc[u[i]], i);
    start[v[i]].push_back(i);
  }
  
  sort(path, path + M);
  
  for (int i = 0; i < M; i++)
    pos[path[i].second] = i;
    
  go(1, 0);
  
  ll sol = 0;
  for (int i = 0; i < E[1].size(); i++)
    add(sol, dp[E[1][i]]);
  
  return sol < INF ? sol : -1;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}