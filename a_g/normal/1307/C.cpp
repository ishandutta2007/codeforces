#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  long long ans = 1;
  for (char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    long long occ = 0;
    for (char z: s) {
      if (z == c) {
        occ += cnt++;
      }
    }
    ans = max<long long>({ans, occ, cnt});
  }
  for (char c = 'a'; c <= 'z'; c++) {
    for (char d = 'a'; d <= 'z'; d++) {
      if (c == d) continue;
      int cnt = 0;
      long long occ = 0;
      for (char z: s) {
        if (z == c) cnt++;
        else if (z == d) occ += cnt;
      }
      ans = max(ans, occ);
    }
  }
  cout << ans << '\n';
}