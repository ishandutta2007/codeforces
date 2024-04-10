#include <bits/stdc++.h>
using namespace std;

int cnt[26][26];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      cnt[s[0]-'a'][s[1]-'a']++;
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        for (int k = j+1; k < 26; k++) {
          ans += 1LL * cnt[i][j] * cnt[i][k];
          ans += 1LL * cnt[j][i] * cnt[k][i];
        }
      }
    }
    cout << ans << '\n';
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        cnt[i][j] = 0;
      }
    }
  }
}