#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1.5e3 + 5;
const int BASE = 3137;
const int MOD = 998244353;
const int INF = 1e9;

struct triple {
  int who, lower, upper;
};

int N;
int a[MAXN][MAXN];
unordered_map <int, vector <triple>> ranges[MAXN];
vector <int> good[MAXN];
vector <int> ch[2 * MAXN];
int dad[2 * MAXN];
int pot[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", a[i] + j);
}

inline void add(int &x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

void process(int x) {
  vector <int> other(N);
  iota(other.begin(), other.end(), 0);
  other.erase(other.begin() + x);
  sort(other.begin(), other.end(), [&](int lhs, int rhs) { return a[x][lhs] < a[x][rhs]; });
  int hsh = pot[x];
  for (int i = 0; i < N; i++) {
    int lo = i ? a[x][other[i - 1]] : 0;
    int hi = i < N - 1 ? a[x][other[i]] : INF;
    ranges[i + 1][hsh].push_back({x, lo, hi});
    if (i < N - 1)
      add(hsh, pot[other[i]]);
  }
}

vector <int> conv(const vector <int> &a, const vector <int> &b) {
  int deg_a = (int)a.size() - 1;
  int deg_b = (int)b.size() - 1;
  vector <int> c(deg_a + deg_b + 1);
  for (int i = 0; i <= deg_a; i++)
    for (int j = 0; j <= deg_b; j++)
      add(c[i + j], mul(a[i], b[j]));
  return c;
}

vector <int> dfs(int x) {
  vector <int> res{!ch[x].empty(), 0};
  for (auto it : ch[x]) 
    res = conv(res, dfs(it));
  add(res[1], 1);
  return res;
}

void solve() {
  pot[0] = 1;
  for (int i = 1; i < N; i++)
    pot[i] = mul(pot[i - 1], BASE);   
  for (int i = 0; i < N; i++)
    process(i);
  int label = 0;
  for (int i = 1; i <= N; i++)
    for (auto it : ranges[i]) {
      vector <triple> tmp = it.second;
      assert(tmp.size() <= i);
      if (tmp.size() == i) {
        int mx = 0, mn = INF;
        for (auto elem : tmp) {
          mx = max(mx, elem.lower);
          mn = min(mn, elem.upper);
        }
        if (mx < mn) {
          for (auto elem : tmp)
            good[elem.who].push_back(label);
          label++;
        }
      }
    }
  for (int i = 0; i < N; i++)
    for (int j = 1; j < good[i].size(); j++)
      dad[good[i][j - 1]] = good[i][j];
  for (int i = 0; i < label - 1; i++) 
    ch[dad[i]].push_back(i);
  vector <int> ans = dfs(label - 1);
  for (int i = 1; i <= N; i++)
    printf("%d ", ans[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}