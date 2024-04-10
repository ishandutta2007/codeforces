#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, H;
    cin >> n >> H;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int p = a[n-1];
    int q = a[n-2];
    int ans = 2*(H/(p+q));
    H -= (p+q)*ans/2;
    if (H > p) ans += 2;
    else if (H > 0) ans++;
    cout << ans << '\n';
  }
}