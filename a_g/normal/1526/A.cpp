#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b(2*n);
    for (int i = 0; i < n; i++) b[2*i] = a[i];
    for (int i = 0; i < n; i++) b[2*i+1] = a[n+i];
    for (int x: b) cout << x << ' ';
    cout << '\n';
  }
}