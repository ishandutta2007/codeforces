#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int MAXL = 22;
const int INF = 0x3f3f3f3f;

int N;
vector <int> diff;
int best[1 << MAXL];
vector <pii> ch[MAXN];
int dep[MAXN], sub[MAXN], mask[MAXN];
int ans[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 2; i <= N; i++) {
    int p;
    char c;
    scanf("%d %c", &p, &c);
    ch[p].push_back({i, c - 'a'});
  }
}

inline void update(int &ref, int val) {
  if (val > ref)
    ref = val;
}

int dfs_prep(int x) {
  sub[x] = 1;
  for (auto it : ch[x]) {
    dep[it.first] = dep[x] + 1;
    mask[it.first] = mask[x] ^ 1 << it.second;
    sub[x] += dfs_prep(it.first);
  }
  return sub[x];
}

void get_subtree(int x, vector <int> &v) {
  v.push_back(x);
  for (auto it : ch[x])
    get_subtree(it.first, v);
}

void dfs_solve(int x) {
  int heavy = -1;
  for (auto it : ch[x])
    if (heavy == -1 || sub[it.first] > sub[heavy])
      heavy = it.first;
  vector <vector <int>> other;
  for (auto it : ch[x])
    if (it.first != heavy) {
      dfs_solve(it.first);
      vector <int> tmp;
      get_subtree(it.first, tmp);
      for (auto elem : tmp)
        best[mask[elem]] = -INF;
      other.push_back(tmp);
    }
  other.push_back({x});
  if (heavy != -1)
    dfs_solve(heavy);
  for (auto it : other) {
    for (auto elem : it) 
      for (auto delta : diff)
        update(ans[x], dep[elem] + best[mask[elem] ^ delta]);
    for (auto elem : it)
      update(best[mask[elem]], dep[elem]);
  }
  if (heavy != -1)
    ans[x] -= 2 * dep[x];
  for (auto it : ch[x])
    update(ans[x], ans[it.first]);
}

void solve() {
  memset(best, -INF, sizeof best);
  diff.push_back(0);
  for (int i = 0; i < MAXL; i++)
    diff.push_back(1 << i);
  dfs_prep(1);
  dfs_solve(1);
  for (int i = 1; i <= N; i++)
    printf("%d ", ans[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}