#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;

int n;
ll p, q, r, a[N];
ll one[N], two[N], three[N];

int main() {
  scanf("%d %lld %lld %lld", &n, &p, &q, &r);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  one[n + 1] = two[n + 1] = three[n + 1] = -8e18 - 10;
  for (int i = n; i; --i) {
    one[i] = r * a[i];
    one[i] = max(one[i], one[i + 1]);
  }
  for (int i = n; i; --i) {
    two[i] = q * a[i] + one[i];
    two[i] = max(two[i], two[i + 1]);
  }
  for (int i = n; i; --i) {
    three[i] = p * a[i] + two[i];
    three[i] = max(three[i], three[i + 1]);
  }
  printf("%lld\n", three[1]);
  return 0;
}