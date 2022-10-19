#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int k[N];
int h[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> k[i];
    for (int i = 0; i < n; i++) cin >> h[i];

    long long ans = 0;
    int ptr = n-1;
    while (ptr >= 0) {
      int endpt = k[ptr];
      int startpt = k[ptr]-h[ptr]+1;
      while (ptr >= 1 && startpt <= k[ptr-1]) {
        ptr--;
        startpt = min(startpt, k[ptr]-h[ptr]+1);
      }
      int d = endpt-startpt+1;
      ans += 1LL*d*(d+1)/2;
      ptr--;
    }

    cout << ans << '\n';
  }
}