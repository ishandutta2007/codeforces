#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve() {
  int N;
  scanf("%d", &N);
  ll lcm = 1;
  bool ok = true;
  for (int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    if (lcm <= 1e9)
      lcm = lcm / __gcd(lcm, (ll)i + 1) * (i + 1);
    if (!(x % lcm))
      ok = false;
  }
  return ok;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    puts(solve() ? "YES" : "NO");
  return 0;
}