#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> counts(n+1);
    vector<int> a(n);
    vector<int> indices(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      counts[a[i]]++;
      indices[a[i]] = i;
    }
    string ans(n, '0');
    int l = 0;
    int r = n-1;
    for (int j = 1; j < n; j++) {
      if (!counts[j]) break;
      ans[n-j] = '1';
      if (counts[j] > 1) break;
      if (indices[j] == r) {
        r--;
        continue;
      }
      if (indices[j] == l) {
        l++;
        continue;
      }
      break;
    }
    ans[0] = '1';
    for (int i = 1; i <= n; i++) {
      if (counts[i] != 1) {
        ans[0] = '0';
        break;
      }
    }

    cout << ans << '\n';
  }
}