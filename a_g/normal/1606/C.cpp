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
    k++;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n-1);
    for (int i = 0; i < n-1; i++) {
      b[i] = (ll)pow(10, a[i+1]-a[i])-1;
    }
    int used = 0;
    ll ans = 0;
    int index = 0;
    while (used < k) {
      if (index >= n-1) {
        ans += (k-used)*(ll)pow(10LL, a[n-1]);
        used = k;
      }
      else {
        int v = min(b[index], k-used);
        ans += v*(ll)(pow(10, a[index]));
        used += v;
        index++;
      }
    }
    cout << ans << endl;
  }
}