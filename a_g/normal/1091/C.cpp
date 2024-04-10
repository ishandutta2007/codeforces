#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> f;
  for (int k = 1; 1LL*k*k <= n; k++) {
    if (n%k == 0) {
      f.push_back(n/k+1LL*k*(n/k)*(n/k-1)/2);
      if (n/k > k) {
        f.push_back(k+1LL*(n/k)*k*(k-1)/2);
      }
    }
  }
  sort(f.begin(), f.end());
  for (long long z: f) {
    cout << z << ' ';
  }
  cout << '\n';
}