// Baba
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int BIT[N];
void update(int x, int add) {
  for (; x < N; x += x ^ (x & (x - 1))) BIT[x] += add;
}
int query(int x) {
  if (x < 0) return 0;
  int ret = 0;
  for (; x; x = (x & (x - 1))) ret += BIT[x];
  return ret;
}
int query(int L, int R) { return query(R) - query(L - 1); }
int A[N], dp[N];
int main() {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", A + i);
  }
  sort(A + 1, A + 1 + n);
  dp[0] = 1;
  for (int i = k; i <= n; i++) {
    // not possible to group them together in same box.
    if (A[i] - A[i - k + 1] > d) continue;
    int high = i - k;
    int low = lower_bound(A + 1, A + 1 + n, A[i] - d) - A - 1;
    dp[i] |= query(low, high) > 0;
    dp[i] |= dp[low];
    update(i, dp[i]);
  }
  puts(dp[n] ? "YES" : "NO");
  return 0;
}