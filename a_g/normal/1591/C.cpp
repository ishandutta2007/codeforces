#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x >= 0) pos.push_back(x);
      else neg.push_back(-x);
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end(), greater<int>());
    vector<int> vals;
    for (int i = 0; i < pos.size(); i += k) {
      vals.push_back(pos[i]);
    }
    for (int i = 0; i < neg.size(); i += k) {
      vals.push_back(neg[i]);
    }
    ll ans = 2*accumulate(vals.begin(), vals.end(), 0LL) - *max_element(vals.begin(), vals.end());
    cout << ans << '\n';
  }
}