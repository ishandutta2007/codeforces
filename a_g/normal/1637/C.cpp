#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 3 && a[1]&1) {
      cout << "-1\n";
      continue;
    }
    bool good = 0;
    long long x = accumulate(a.begin()+1, a.begin()+n-1, 0LL);
    for (int i = 1; i < n-1; i++) {
      if (a[i] >= 2) good = 1;
      if (a[i]&1) x++;
    }
    if (!good) {
      cout << "-1\n";
      continue;
    }
    cout << x/2 << '\n';
  }
}