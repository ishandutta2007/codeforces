#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> cnt(26);
    for (char c: s) cnt[c-'a']++;
    for (int i = 0; i < k; i++) {
      int j = 0;
      while (cnt[j] >= i+1) j++;
      j = min(j, n/k);
      char c = j+'a';
      cout << c;
    }
    cout << '\n';
  }
}