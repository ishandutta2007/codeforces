#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int N;
int a[MAXN], b[MAXN];
int w[MAXN], p[MAXN];
int idx[MAXN];
vector <int> ch[MAXN];
ll subtree[MAXN], diff[MAXN];
ll dp_min[MAXN], dp_max[MAXN];
ll val[MAXN], t[MAXN];
ll cost[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    scanf("%d%d%d%d", a + i, b + i, w + i, p + i);
    ch[a[i]].push_back(b[i]);
    idx[b[i]] = i;
  }
}

void bye() {
  puts("-1");
  exit(0);
}

ll calc(int x) {
  for (int i = 0; i < ch[x].size(); i++)
    subtree[x] += calc(ch[x][i]) + w[idx[ch[x][i]]];
  return subtree[x];
}

void go(int x) {
  for (int i = 0; i < ch[x].size(); i++) {
    int nxt = ch[x][i];
    go(nxt);
    ll tmp = max(diff[nxt], dp_min[nxt]);
    if (tmp > dp_max[nxt])
      bye();
    dp_min[x] += tmp;
    val[nxt] = min(dp_max[nxt] - diff[nxt], (ll)min(w[idx[nxt]] - 1, p[idx[nxt]]));
    if (val[nxt] < 0)
      bye();
    dp_max[x] += val[nxt] + dp_max[nxt];
  }   
}

ll check1(int x, ll tmp) {
  ll res = 0;
  for (int i = 0; i < ch[x].size(); i++) {
    int nxt = ch[x][i];
    t[nxt] = min(tmp, val[nxt]);
    tmp -= t[nxt];
    res += t[nxt] + dp_max[nxt];
  }
  return res;
}

ll check2(int x, ll tmp) {
  ll res = 0;
  for (int i = 0; i < ch[x].size(); i++) {
    int nxt = ch[x][i];
    cost[nxt] = min(dp_max[nxt] - dp_min[nxt], tmp);
    tmp -= cost[nxt];
    res += t[nxt] + dp_min[nxt] + cost[nxt];    
  }
  return res;
}

void dfs(int x, ll curr) {
  ll lo = 0, hi = 0;
  for (int i = 0; i < ch[x].size(); i++)
    hi += val[ch[x][i]];
  
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    if (check1(x, mid) >= curr)
      hi = mid;
    else
      lo = mid + 1;
  }
  check1(x, lo);
  
  hi = 0;
  for (int i = 0; i < ch[x].size(); i++) {
    int nxt = ch[x][i];
    dp_min[nxt] = max(dp_min[nxt], t[nxt] + diff[nxt]);
    hi += dp_max[nxt] - dp_min[nxt];
  }
  
  lo = 0;
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    if (check2(x, mid) >= curr)
      hi = mid;
    else
      lo = mid + 1;
  }
  check2(x, lo);
  
  for (int i = 0; i < ch[x].size(); i++) {
    int nxt = ch[x][i];
    w[idx[nxt]] -= (int)t[nxt];
    p[idx[nxt]] -= (int)t[nxt];
    dfs(nxt, dp_min[nxt] + cost[nxt]);
  }
}

void solve() {
  calc(1);
  for (int i = 1; i <= N; i++)
    diff[i] = subtree[i] - p[idx[i]];
  
  go(1);
  dfs(1, dp_min[1]);
  
  printf("%d\n", N);
  for (int i = 1; i < N; i++)
    printf("%d %d %d %d\n", a[i], b[i], w[i], p[i]);
}

int main() {
  load();
  solve();
  return 0;
}