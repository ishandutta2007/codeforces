#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll ans = 0;
    int zeroes = 0;
    while (n--) {
      int v;
      cin >> v;
      if (v==1) ans++;
      if (v==0) zeroes++;
    }
    cout << (ans<<zeroes) << endl;
  }
}