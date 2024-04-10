#include <bits/stdc++.h>
using namespace std;

long long tri(int m) {
  return 1LL * m * (m+1)/2;
}

long long calc(int k) {
  int m = k/3;
  if (k % 3 == 0) {
    return 2*tri(2*m-1)+4*tri(m);
  }
  if (k % 3 == 1) {
    return calc(k+2)-(8*(m+1)-2);
  }
  return calc(k+1)-(4*(m+1));
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int low = 0;
    int high = 1e5;
    while (high - low > 1) {
      int mid = (low+high)/2;
      if (calc(mid) >= n) high = mid;
      else low = mid;
    }
    cout << high << '\n';
  }
}