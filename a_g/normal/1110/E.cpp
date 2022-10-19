#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), ad(n-1), bd(n-1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) ad[i-1] = a[i]-a[i-1];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (i) bd[i-1] = b[i]-b[i-1];
  }

  sort(ad.begin(), ad.end());
  sort(bd.begin(), bd.end());
  cout << (a[0] != b[0] || ad != bd ? "No" : "Yes") << '\n';
}