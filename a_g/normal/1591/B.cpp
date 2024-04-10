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
    int M = *max_element(a.begin(), a.end());
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == M) index = i;
    }
    int cur = -1;
    int ans = -1;
    for (int i = n-1; i >= index; i--) {
      if (a[i] > cur) {
        cur = a[i];
        ans++;
      }
    }
    cout << ans << '\n';
  }
}