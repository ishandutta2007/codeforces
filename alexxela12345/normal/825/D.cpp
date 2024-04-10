#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  string s;
  string t;
  cin >> s >> t;
  vector<int> cnt1(26);
  vector<int> cnt2(cnt1);
  int cnt = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '?') {
      cnt++;
    } else {
      cnt1[s[i] - 'a']++;
    }
  }
  for (int i = 0; i < (int) t.size(); i++) {
    cnt2[t[i] - 'a']++;
  }
  int l = 0;
  int r = 1e7;
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    int nd = 0;
    for (int i = 0; i < 26; i++) {
      nd += max(0LL, cnt2[i] * m - cnt1[i]);
    }
    if (nd <= cnt) {
      l = m;
    } else {
      r = m;
    }
  }
  multiset<char> add;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < max(0LL, cnt2[i] * l - cnt1[i]); j++) {
      add.insert(i + 'a');
    }
  }
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '?') {
      if (!add.empty()) {
        cout << *add.begin();
        add.erase(add.begin());
      } else {
        cout << 'a';
      }
    } else {
      cout << s[i];
    }
  }
  cout << endl;
}