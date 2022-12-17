#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn = 1e5 + 10;
int n;

bool vis[maxn], use[maxn];
vector <int> G[maxn];

vector <pii> ans;

void solve() {
  cin >> n;
  rep(i, 1, n) {
    vis[i] = 0;
    G[i].clear();
    int x = read();
    while (x--) G[i].push_back(read());
  }
  bool flg = 0;
  ans.clear();
  rep(i, 1, n) {
    use[i] = 0;
    for (int x : G[i]) {
      if (!vis[x]) {
        vis[x] = 1; use[i] = 1;
        break;
      }
    }
  }
  vector <int> vec;
  rep(i, 1, n) if (!vis[i]) vec.push_back(i);
  reverse(vec.begin(), vec.end());
  rep(i, 1, n) if (!use[i]) {
    int x = vec.back();
    vec.pop_back();
    flg = 1;
    ans.push_back({i, x});
  }
  if (!flg) {
    puts("OPTIMAL");
    return;
  }
  puts("IMPROVE");
  pii p = ans[0];
  printf("%d %d\n", p.first, p.second);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}