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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    for (int i = 0; i < n-1; i++) {
      if (a[i] == a[i+1]) b.push_back(i);
    }
    if (b.size() <= 1) {
      cout << "0\n";
      continue;
    }
    cout << max(1, b.back()-b[0]-1) << '\n';
  }
}