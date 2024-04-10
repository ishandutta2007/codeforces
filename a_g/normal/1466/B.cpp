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
    for (int& x: a) cin >> x;
    for (int i = n-1; i >= 0; i--) {
      if (i == n-1 || a[i] < a[i+1]-1) a[i]++;
    }
    cout << unique(a.begin(), a.end()) - a.begin() << '\n';
  }
}