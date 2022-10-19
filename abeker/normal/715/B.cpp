#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1005;
const int MAXM = 10005;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int N, M, L;
int s, t;
vector <pii> E[MAXN];
vector <int> id;
int u[MAXM], v[MAXM], w[MAXM];
ll dist[MAXN];

struct cmp {
  bool operator ()(const int &lhs, const int &rhs) const {
    if (dist[lhs] != dist[rhs]) 
      return dist[lhs] < dist[rhs];
    return lhs < rhs;
  }
};

set <int, cmp> S;

void load() {
  scanf("%d%d%d%d%d", &N, &M, &L, &s, &t);
  for (int i = 0; i < M; i++)
    scanf("%d%d%d", u + i, v + i, w + i);  
}

ll calc(ll val) {
  for (int i = 0; i < id.size(); i++)
    w[id[i]] = 1;
  ll bound = val / L;
  for (int i = 0; i < bound; i++)
    w[id[i]] += L;
  if (bound < id.size()) 
    w[id[bound]] += (int)(val % L);
  
  for (int i = 0; i < N; i++)
    E[i].clear();
  for (int i = 0; i < M; i++) {
    E[u[i]].push_back(pii(v[i], w[i]));
    E[v[i]].push_back(pii(u[i], w[i]));
  }
  
  memset(dist, INF, sizeof dist);  
  dist[s] = 0;
  for (int i = 0; i < N; i++)
    S.insert(i);
  while (!S.empty()) {
    int x = *S.begin();
    S.erase(x);
    for (int i = 0; i < E[x].size(); i++) {
      int nxt = E[x][i].first;
      ll cand = dist[x] + E[x][i].second;
      if (S.count(nxt) && cand < dist[nxt]) {
        S.erase(nxt);
        dist[nxt] = cand;
        S.insert(nxt);
      }
    }
  }
  
  return dist[t];
}

void solve() {
  for (int i = 0; i < M; i++) 
    if (!w[i]) id.push_back(i);
  
  ll lo = 0, hi = (ll)id.size() * L;
  if (calc(lo) > L || calc(hi) < L) {
    puts("NO");
    return;
  }
  
  while (lo < hi) {
    ll mid = (lo + hi) / 2;
    if (calc(mid) >= L) hi = mid;
    else lo = mid + 1;
  }
  calc(lo);
  
  puts("YES");
  for (int i = 0; i < M; i++)
    printf("%d %d %d\n", u[i], v[i], w[i]);
}

int main() {
  load();
  solve();
  return 0;
}