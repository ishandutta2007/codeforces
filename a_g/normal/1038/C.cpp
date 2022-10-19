#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  long long d = 0;
  vector<int> a(2*n);
  for (int i = 0; i < 2*n; i++) {
    cin >> a[i];
    if (i < n) d += a[i];
    else d -= a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < 2*n; i++) {
    if (i&1) d -= a[i];
    else d += a[i];
  }
  cout << d/2 << '\n';
}