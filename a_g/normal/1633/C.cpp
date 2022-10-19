#include <bits/stdc++.h>
using namespace std;

long long ceil(long long x, long long y) {
  return (x+y-1)/y;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long hc, hm, a, dc, dm;
    int k, w;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    bool win = 0;
    for (int i = 0; i <= k; i++) {
      if (ceil(hm, dc+i*w) <= ceil(hc+(k-i)*a, dm)) {
        win = 1;
        break;
      }
    }

    cout << (win ? "YES" : "NO") << '\n';
  }
}