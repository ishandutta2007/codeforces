#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int p, k;
  cin >> p >> k;
  int power;
  if (k == 0) {
    power = p-1;
  }
  else {
    int order = 1;
    int u = k;
    while (u != 1) {
      order++;
      u = 1LL * k * u % p;
    }
    power = (p-1)/(order) + (k == 1 ? 1 : 0);
  }
  cout << expmod(p, power, MOD) << endl;
}