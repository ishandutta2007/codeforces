#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int pow = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      while (a[i] % 2 == 0) {
        a[i] /= 2;
        pow++;
      }
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    ll m = *max_element(a.begin(), a.end());
    ll ans = (sum-m) + (m<<pow);
    cout << ans << '\n';
  }
}