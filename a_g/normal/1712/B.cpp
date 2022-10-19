#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for (int i = n-2; i >= 0; i -= 2) {
      swap(ans[i], ans[i+1]);
    }
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}