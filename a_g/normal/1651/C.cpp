#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    long long ans = min(abs(a[0]-b[0])+abs(a[n-1]-b[n-1]), abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
    int d[4] = {INF, INF, INF, INF};
    for (int x: b) {
      d[0] = min(d[0], abs(x-a[0]));
      d[1] = min(d[1], abs(x-a[n-1]));
    }
    for (int x: a) {
      d[2] = min(d[2], abs(x-b[0]));
      d[3] = min(d[3], abs(x-b[n-1]));
    }
    ans = min(ans, 0LL+abs(a[0]-b[0])+d[1]+d[3]);
    ans = min(ans, 0LL+abs(a[n-1]-b[n-1])+d[0]+d[2]);
    ans = min(ans, 0LL+abs(a[n-1]-b[0])+d[0]+d[3]);
    ans = min(ans, 0LL+abs(a[0]-b[n-1])+d[1]+d[2]);
    ans = min(ans, 0LL+d[0]+d[1]+d[2]+d[3]);
    cout << ans << '\n';
  }
}