#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n), x(n+1), a(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    a[i] = b[i] + x[i];
    x[i+1] = max(x[i], a[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i==n-1];
  }
}