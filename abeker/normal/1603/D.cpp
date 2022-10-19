#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int LOG = 17;
const ll INF = 1e18;

struct Node {
  ll mini, lazy;
  Node() : mini(INF), lazy(0) {}
};

class Tournament {
  Node tour[2 * offset];
public:
  void push(int x, ll val) {
    tour[x].mini += val;
    tour[x].lazy += val;
  }
  void prop(int x) {
    if (!tour[x].lazy || x >= offset)
      return;
    push(2 * x, tour[x].lazy);
    push(2 * x + 1, tour[x].lazy);
    tour[x].lazy = 0;
  }
  void update(int x, int lo, int hi, int from, int to, ll val) {
    if (lo >= to || hi <= from)
      return;
    if (lo >= from && hi <= to) {
      push(x, val);
      return;
    }
    prop(x);
    int mid = lo + hi >> 1;
    update(2 * x, lo, mid, from, to, val);
    update(2 * x + 1, mid, hi, from, to, val);
    tour[x].mini = tour[2 * x].mini < tour[2 * x + 1].mini ? tour[2 * x].mini : tour[2 * x + 1].mini;
  }
  ll query() const {
    return tour[1].mini;
  }
};

int phi[MAXN];
vector <int> divs[MAXN];
ll dp[LOG][MAXN];

void init() {
  for (int i = 1; i < MAXN; i++) {
    phi[i] += i;
    divs[i].push_back(i);
    for (int j = 2 * i; j < MAXN; j += i) {
      divs[j].push_back(i);
      phi[j] -= phi[i];
    }
  }
  for (int n = 1; n < MAXN; n++)
    dp[1][n] = (ll)n * (n + 1) / 2;
  for (int k = 2; k < LOG; k++) {
    Tournament trans;
    for (int n = 1; n < MAXN; n++) {
      for (auto it : divs[n])
        trans.update(1, 0, offset, 1, it, phi[n / it]);
      dp[k][n] = trans.query();
      trans.update(1, 0, offset, n, n + 1, dp[k - 1][n] - INF);
    }
  }
}

int advance() {
  int res = 0;
  int d = getchar();
  while (d < 48 || d > 57) 
    d = getchar();
  do {
    res = res * 10 + d - 48;
    d = getchar();
  } while (d > 47 && d < 58);
  return res;
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, k;
    n = advance();
    k = advance();
    printf("%lld\n", k < LOG ? dp[k][n] : n);
  }
  return 0;
}