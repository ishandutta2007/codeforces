#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a-b) > 1 || a+b > n-2) {
    cout << -1 << '\n';
    return;
  }
  if (abs(a-b) == 1) {
    vector<int> ans;
    for (int i = 0; i < max(a, b); i++) {
      ans.push_back(n-2*i-1);
      ans.push_back(n-2*i);
    }
    for (int i = n-2*max(a, b); i >= 1; i--) {
      ans.push_back(i);
    }
    if (a < b) {
      for (int i = 0; i < n; i++) {
        ans[i] = n+1-ans[i];
      }
    }
    for (int i: ans) cout << i << ' ';
    cout << '\n';
  }
  else {
    vector<int> ans;
    for (int i = 0; i < a; i++) {
      ans.push_back(n-2*i-1);
      ans.push_back(n-2*i);
    }
    for (int i = 1; i <= n-2*a; i++) {
      ans.push_back(i);
    }
    for (int i: ans) cout << i << ' ';
    cout << '\n';
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}