#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN], b[MAXN];
int c[MAXN], inv_b[MAXN];
bool vis[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
}

ll solve() {
  for (int i = 1; i <= N; i++)
    inv_b[b[i]] = i;
  for (int i = 1; i <= N; i++) {
    c[i] = a[inv_b[i]];
    vis[i] = false;
  }
  int sum = 0;
  for (int i = 1; i <= N; i++)
    if (!vis[i]) {
      int len = 0;
      for (int j = i; !vis[j]; j = c[j]) {
        vis[j] = true;
        len++;
      }
      sum += len / 2;
    }
  ll sol = 0;
  for (int i = 1; i <= sum; i++)
    sol += N + 1 - 2 * i;
  return 2 * sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%lld\n", solve());
  }
  return 0;
}