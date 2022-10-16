#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ll u, v;
    scanf("%lld%lld", &u, &v);
    printf("%lld %lld\n", -u * u, v * v);
  }   
}