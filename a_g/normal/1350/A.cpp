#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int minp;
    for (int i = 2; i <= 1e6; i++) {
      if (n % i == 0) {
        minp=i;
        break;
      }
    }
    int ans = n+minp+2*k-2;
    cout << ans << endl;
  }
}