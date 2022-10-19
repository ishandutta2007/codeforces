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
    sort(a.begin(), a.end());
    if (n > 1 && a[n-1]-a[n-2] > 1) {
      cout << "NO\n";
      continue;
    }
    long long tot = accumulate(a.begin(), a.end(), 0LL);
    long long mx = *max_element(a.begin(), a.end());
    cout << (tot >= 2*mx-1 ? "YES" : "NO") << '\n';
  }
}