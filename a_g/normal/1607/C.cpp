#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = *min_element(a, a+n);
    sort(a, a+n);
    for (int i = 0; i < n-1; i++) {
      ans = max(ans, a[i+1]-a[i]);
    }
    cout << ans << '\n';
  }
}