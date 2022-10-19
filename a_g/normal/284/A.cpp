#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int p;
  cin >> p;
  int ans = 0;
  for (int i = 1; i < p; i++) {
    if (__gcd(i, p-1) == 1) ans++;
  }
  cout << ans << endl;
}