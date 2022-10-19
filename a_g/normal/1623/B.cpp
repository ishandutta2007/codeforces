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
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i].first >> c[i].second;
    }
    vector<pair<int, int>> a = c;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      int l = c[i].first;
      int r = c[i].second;
      if (l == r) {
        cout << l << " " << r << " " << l << '\n';
      }
      else {
        if (a[0].first == l && a[0].second == r) {
          cout << l << " " << r << " " << l << '\n';
        }
        else {
          auto it = lower_bound(a.begin(), a.end(), make_pair(l, r))-1;
          if (it->first == l && it->second != r) {
            cout << l <<  " " << r << " " << it->second+1 << '\n';
          }
          else {
            cout << l << " " << r << " " << l << '\n';
          }
        }
      }
    }
    cout << '\n';
  }
}