#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  sort(a.begin(), a.end(), greater<int>());
  vector<long long> s(n+1);
  for (int i = 0; i < n; i++) s[i+1] = s[i] + a[i];
  int r = n;
  long long low = 0;
  long long high = n;
  for (int k = 1; k <= n+1; k++) {
    while (r > 0 && a[r-1] < k) r--;
    if (k < n+1) {
      // a_0+...+a_{k-1} <= k(k-1)+a_{n+1}+sum from i = k to n-1 of min(d_i, k)
      low = max(low, s[k]-1LL*k*(k-1)-(r >= k ? s[n]-s[r]+1LL*k*(r-k) : s[n]-s[k-1]));
    }
    // a_0+...+a_{k-2}+a_{n+1} <= k(k-1)+sum from i = k-1 to n-1 of min(d_i, k)
    high = min(high, 1LL*k*(k-1)-s[k-1]+(r >= k-1 ? s[n]-s[r]+1LL*k*(r-k+1) : s[n]-s[k-1]));
  }
  if (low%2 != s[n]%2) low++;
  if (high%2 != s[n]%2) high--;
  if (low > high) {
    cout << "-1\n";
  }
  else {
    for (long long x = low; x <= high; x += 2) {
      cout << x << " \n"[x==high];
    }
  }
}