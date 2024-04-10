#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    if (n > 0) cout << -n+1 << " " <<  n << endl;
    else if (n < 0) cout << n << " " <<  -n+1 << endl;
    else cout << -1 << " " <<  1 << endl;
  }
}