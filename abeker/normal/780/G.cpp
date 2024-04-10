#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int offset = 1 << 17;
const int MOD = 1000000007;

struct barrier {
  int u, l, r, s;
  barrier(int u, int l, int r, int s) : 
    u(u), l(l), r(r), s(s) {}
  barrier() : u(0), l(0), r(0), s(0) {}
  void input() {
    scanf("%d%d%d%d", &u, &l, &r, &s);
  }
  bool operator <(const barrier &rhs) const {
    return u < rhs.u;
  }
};

int H, W, N;
barrier B[MAXN];
set <pii> S[2 * offset];
int dp[MAXN];

void load() {
  scanf("%d%d%d", &H, &W, &N);
  for (int i = 1; i <= N; i++)
    B[i].input();
}

void update(int x, int lo, int hi, int from, int to, pii val) {
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    while (!S[x].empty() && *S[x].begin() < val)
      S[x].erase(S[x].begin());
    S[x].insert(val);
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, val);
  update(2 * x + 1, mid, hi, from, to, val);
}

void update(int from, int to, pii val) {
  update(1, 0, offset, from, to, val);
}

int query(int h, int pos) {
  int mx = 0;
  for (pos += offset; pos; pos /= 2) {
    if (S[pos].empty())
      continue;
    set <pii> :: iterator it = S[pos].lower_bound(pii(h, 0));
    if (it != S[pos].end())
      mx = max(mx, it -> second);
  }
  return mx;
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  return x;
}

int solve() {
  sort(B + 1, B + N + 1);
  
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    int a = B[i].l > 1 ? query(B[i].u, B[i].l - 1) : query(B[i].u, B[i].r + 1);
    int b = B[i].r < W ? query(B[i].u, B[i].r + 1) : query(B[i].u, B[i].l - 1);
    dp[i] = add(dp[a], dp[b]);
    update(B[i].l, B[i].r + 1, pii(B[i].u + B[i].s, i));
  }
  
  int sol = 0;
  for (int i = 1; i <= W; i++)
    sol = add(sol, dp[query(H + 1, i)]);
  
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}