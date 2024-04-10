#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  ll m = (n+1)/2;
  vector<int> a(2*n);
  for (int i = 0; i < n; i++) {
    int index = (m*i) % n;
    cin >> a[index];
    a[index + n] = a[index];
  }
  ll sum = 0;
  for (int i = 0; i < m; i++) {
    sum += a[i];
  }
  ll ans = sum;
  for (int i = 0; i < n; i++) {
    sum += a[m+i];
    sum -= a[i];
    ans = max(ans, sum);
  }
  cout << ans << endl;
}