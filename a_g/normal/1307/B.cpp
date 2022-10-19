#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& y: a) cin >> y;
    int m = *max_element(a.begin(), a.end());
    if (count(a.begin(), a.end(), x)) {
      cout << "1\n";
      continue;
    }
    cout << max(2, (x+m-1)/m) << '\n';
  }
}