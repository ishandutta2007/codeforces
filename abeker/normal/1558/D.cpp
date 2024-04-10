#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;
const int MOD = 998244353;
const int INF = 2e9;

class Tournament {
  int n, offset;
  vector <int> sum;
public:
  Tournament(deque <int> d) {
    n = d.size();
    for (offset = 1; offset < n; offset *= 2);
    sum.resize(2 * offset);
    for (int i = 0; i < n; i++) 
      sum[i + offset] = d[i] - (i ? d[i - 1] : 0);
    for (int i = offset - 1; i; i--)
      sum[i] = sum[2 * i] + sum[2 * i + 1];
  }
  void update(int x) {
    if (x >= n)
      return;
    for (x += offset; x; x /= 2)
      sum[x]++;
  }
  int getFirst(int x, int val) const {
    if (x >= offset)
      return x - offset;
    if (sum[2 * x] >= val)
      return getFirst(2 * x, val);
    return getFirst(2 * x + 1, val - sum[2 * x]);
  }
  deque <int> getValues() const {
    deque <int> res = {sum[offset]};
    for (int i = 1; i < n; i++)
      res.push_back(res.back() + sum[i + offset]);
    return res;
  }
};

int N, M;
int fact[MAXN], inv[MAXN];
int a[MAXN];

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

void init() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = pot(fact[i], MOD - 2);
  }
}

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++)
    scanf("%*d%d", a + i);
}

int choose(int n, int k) {
  return mul(fact[n], mul(inv[k], inv[n - k]));
}

deque <int> solve(int lo, int hi) {
  if (hi == lo)
    return {INF};
  if (hi == lo + 1)
    return {a[lo] + 1, INF};
  int mid = (lo + hi) / 2;
  deque <int> left = solve(lo, mid);
  Tournament curr(left);
  for (int i = mid; i < hi; i++) 
    curr.update(curr.getFirst(1, a[i]));
  left = curr.getValues();
  deque <int> res, right = solve(mid, hi);
  auto remove_front = [&](deque <int> &d) {
    if (res.empty() || res.back() < d.front())
      res.push_back(d.front());
    d.pop_front();
  };
  while (left.size() > 1 || right.size() > 1)
    remove_front(left.front() < right.front() ? left : right);
  res.push_back(INF);
  return res;
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", choose(2 * N - (int)solve(0, M).size(), N));
  }
  return 0;
}