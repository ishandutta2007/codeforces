#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  cout << fixed << setprecision(10);
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll m = *max_element(a.begin(), a.end());
    ll s = accumulate(a.begin(), a.end(), 0LL)-m;
    cout << m+s/(double)(n-1) << endl;
  }
}