#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N;
int dad[MAXN];
bool bio[MAXN];
int degree[MAXN];
vector <int> adj[MAXN];
pii height[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &height[i].first);
    height[i].second = i;
  }
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs(int x, int p) {
  dad[x] = p;
  for (auto it : adj[x])
    if (it != p)
      dfs(it, x);
}

ll solve() {
  sort(height + 1, height + N + 1);
  dfs(height[N].second, 0);
  auto is_leaf = [&](int x) {
    return degree[x] == 1;
  };
  int leaves = 0;
  auto update_node = [&](int x) {
    leaves -= is_leaf(x);
    degree[x]++;
    leaves += is_leaf(x);
  };
  auto add_node = [&](int x) {
    for (; !bio[x]; x = dad[x]) {
      update_node(x);
      update_node(dad[x]);
      bio[x] = true;
    }
  };
  ll sol = 0;
  bio[height[N].second] = true;
  add_node(height[N - 1].second);
  for (int i = N; i; i--) {
    add_node(height[i].second);
    sol += (ll)(height[i].first - height[i - 1].first) * leaves;
  }
  return sol;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}