#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int maxfreq = 0;
    int pr = a[0]-1;
    int freq = 0;
    for (int val: a) {
      if (val == pr) {
        freq++;
      }
      else {
        pr = val;
        freq = 1;
      }
      maxfreq = max(maxfreq, freq);
    }
    int ans = 0;
    while (maxfreq < n) {
      ans++;
      ans += min(maxfreq, n-maxfreq);
      maxfreq *= 2;
    }
    cout << ans << '\n';
  }
}