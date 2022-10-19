#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    vector<int> freq_a(26), freq_b(26);
    for (char c: a) freq_a[c-'a']++;
    for (char c: b) freq_b[c-'a']++;
    bool ok = 1;
    for (int i = 0; i < 26; i++) {
      if (freq_a[i] < freq_b[i]) {
        ok = 0;
        break;
      }
      if ((freq_a[i]-freq_b[i])%k != 0) {
        ok = 0;
        break;
      }
      if (i+1 < 26) {
        freq_a[i+1] += freq_a[i]-freq_b[i];
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}