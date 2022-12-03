#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 200005
using namespace std;
typedef long long ll;
typedef long double ldouble;
const int LEN = 100000;

int n;
char s[maxn];
int a[maxn], sum0[maxn], S[maxn];

bool check(int lcp, int S) {
  vector<int> lis;
  for (int i = 0; i <= 9; i++) if (S >> i & 1) lis.push_back(i);
  int r = n - lcp - lis.size();
  if (r < 0) return false;
  if (sum0[lcp + r] - sum0[lcp] < r) return true;
  for (int i = lcp + r + 1; i <= n; i++) {
    if (a[i] > lis[i - lcp - r - 1]) return true;
    if (a[i] < lis[i - lcp - r - 1]) return false;
  }
  return false;
}

void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = s[i] - '0';
    S[i] = S[i - 1] ^ (1 << a[i]);
    sum0[i] = sum0[i - 1] + (a[i] == 0);
  }
  if (n & 1) {
    for (int i = 1; i <= n - 1; i++) printf("9");
    puts("");
    return;
  }
  int lcp = n - 1;
  while (lcp && !check(lcp, S[lcp])) lcp--;
  if (!lcp) {
    if (a[1] == 1) {
      for (int i = 1; i <= n - 2; i++) printf("9");
      puts("");
      return;
    }
    printf("%d", a[1] - 1);
    for (int i = 1; i <= n - 2; i++) printf("9");
    printf("%d\n", a[1] - 1);
    return;
  }
  for (int i = a[lcp + 1] - 1; i >= 0; i--) {
    int T = S[lcp] ^ (1 << i);
    vector<int> lis;
    for (int j = 9; j >= 0; j--) if (T >> j & 1) lis.push_back(j);
    int r = n - lcp - 1 - lis.size();
    if (r < 0) continue;
    for (int j = 1; j <= lcp; j++) printf("%d", a[j]);
    printf("%d", i);
    for (int j = 1; j <= r; j++) printf("9");
    for (auto j : lis) printf("%d", j);
    puts("");
    return;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}