#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> d(2*n);
    for (long long& x: d) cin >> x;
    sort(d.begin(), d.end());
    bool good = 1;
    for (int i = 0; i < n; i++) {
      if (d[2*i] != d[2*i+1]) good = 0;
    }
    vector<long long> a(n);
    for (int i = 1; i < n; i++) {
      long long diff = d[2*i]-d[2*i-1];
      if (diff == 0 || diff % (2*i) != 0) good = 0;
      a[i] = a[i-1] + diff/(2*i);
    }
    long long s = accumulate(a.begin(), a.end(), 0LL);
    long long z = d[0] - 2*s;
    if (z <= 0 || z % (2*n) != 0) good = 0;
    cout << (good ? "YES" : "NO") << '\n';
  }
}