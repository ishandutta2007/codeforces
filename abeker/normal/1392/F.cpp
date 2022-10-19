#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int N;
  scanf("%d", &N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    ll h;
    scanf("%lld", &h);
    sum += h;
  }
  
  int pref = sum % N;
  if (!(N % 2)) {
    pref += N / 2;
    pref %= N;
  }
  
  ll x = (sum - pref - (ll)N * (N - 1) / 2) / N;
  for (int i = 0; i < N; i++)
    printf("%lld ", x + i + (i < pref));
  puts("");
  
  return 0;
}