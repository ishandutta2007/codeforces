#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, a, b, s[200233];
int m;

void Main() {
  scanf("%lld%d%lld%lld", &n, &m, &a, &b);
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &s[i]);
  }
  sort(s + 1, s + 1 + m, greater<ll>());
  ll A = abs(a - b) - 1;
  ll B = A + (a < b ? a : n + 1 - a);
  int ans = 0;
  for (int t = 1, i = 1; t <= A && i <= m; t++) {
    while (i <= m && t + s[i] > B) i++;
    if (i <= m) {
      ans++; i++;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    Main();
  }
}