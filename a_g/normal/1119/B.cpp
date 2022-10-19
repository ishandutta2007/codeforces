#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  auto check = [&] (int k) {
    vector<int> b(a.begin(), a.begin()+k);
    sort(b.begin(), b.end());
    long long z = 0;
    for (int i = 1-(k&1); i < k; i+=2) {
      z += b[i];
    }
    return z <= h;
  };
  int low = 0;
  int high = n;
  if (check(n)) {
    cout << n << '\n';
    return 0;
  }
  while (high-low > 1){
    int mid = (low+high)/2;
    if (check(mid)) low = mid;
    else high = mid;
  }
  cout << low << '\n';
}