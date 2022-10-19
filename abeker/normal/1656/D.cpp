#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve() {
  ll N;
  scanf("%lld", &N);
  ll pot = 2;
  for (; !(N % 2); N /= 2)
    pot *= 2;
  if (N == 1)
    return -1;
  return min(N, pot);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    printf("%lld\n", solve());
  return 0;
}