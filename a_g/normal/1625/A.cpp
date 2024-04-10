#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, l;
    cin >> n >> l;
    vector<int> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    int ans = 0;
    for (int i = 0; i < l; i++) {
      int c = 0;
      for (int word: words) {
        if (word&(1<<i)) c++;
      }
      if (c > n/2) ans |= (1<<i);
    }
    cout << ans << '\n';
  }
}