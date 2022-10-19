#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> get(int n) {
  vector <ll> res(n);
  for (auto &it : res)
    scanf("%lld", &it);
  return res;
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  vector <ll> a = get(N);
  vector <ll> b = get(M);  
  ll g = 0;
  for (int i = 1; i < N; i++)
    g = __gcd(g, abs(a[i] - a[i - 1]));
  for (auto it : b)
    printf("%lld ", __gcd(g, a[N - 1] + it));
  puts(""); 
  return 0;
}