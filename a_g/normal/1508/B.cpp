#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    if (n < 64 && k > (1LL<<(n-1))) {
      cout << "-1\n";
      continue;
    }
    k--;
    vector<int> breaks;
    breaks.push_back(0);
    for (int i = 1; i < n; i++) {
      int b = n-i-1;
      if (b > 62 || ((k>>b)&1) == 0) {
        breaks.push_back(i);
      }
    }
    breaks.push_back(n);
    for (int i = 0; i < (int)breaks.size()-1; i++) {
      int l = breaks[i]+1;
      int r = breaks[i+1];
      for (int j = r; j >= l; j--) {
        cout << j << ' ';
      }
    }
    cout << '\n';
  }
}