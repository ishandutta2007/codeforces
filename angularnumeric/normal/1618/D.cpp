#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long sum = 0;
    for (int i = 0; i < n - 2 * k; i++) sum += a[i];
    int i = n - 2 * k;
    while (i < n && k > 0) {
      sum += a[i] / a[n - k];
      i++;
      k--;
    }
    cout << sum << endl;
  }
  return 0;
}