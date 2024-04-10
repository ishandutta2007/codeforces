#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> indices;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i]) {
      indices.push_back(i);
    }
  }
  int z = indices.size();
  long long d = accumulate(a.begin(), a.end(), 0LL);
  if (abs(d) > 1LL*z*k) {
    cout << "-1\n";
    return 0;
  }
  vector<int> vals(z);
  long long u = -d;
  for (int i = 0; i < z; i++) {
    vals[i] = min<long long>(k, u+1LL*(z-i-1)*k);
    u -= vals[i];
  }

  long long ans = 0;
  for (int i = 0; i < max(z, 1); i++) {
    for (int j = 0; j < z; j++) {
      a[indices[j]] = vals[(i+j)%z];
    }
    long long l = 0;
    long long r = 0;
    long long cur = 0;
    for (int x: a) {
      cur += x;
      l = min(cur, l);
      r = max(cur, r);
    }
    ans = max(ans, r-l+1);
  }
  cout << ans << '\n';
}