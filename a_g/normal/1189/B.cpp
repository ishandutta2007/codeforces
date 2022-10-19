#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (a[n-1] >= a[n-2] + a[n-3]) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  cout << a[n-1] << " ";
  for (int i = n-3; i >= 0; i--) {
    cout << a[i] << " ";
  }
  cout << a[n-2] << '\n';
}