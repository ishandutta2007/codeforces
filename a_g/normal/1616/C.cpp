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
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = n-1;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int bad = 0;
        for (int k = 0; k < n; k++) {
          if (i*a[j] + j*a[k] + k*a[i] != j*a[i] + k*a[j] + i*a[k]) bad++;
        }
        ans = min(ans, bad);
      }
    }
    cout << ans << '\n';
  }
}