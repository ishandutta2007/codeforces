#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> partials(n+1, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      partials[i+1][j] = partials[i][j];
    }
    partials[i+1][s[i]-'a']++;
  }

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "Yes\n";
      continue;
    }
    vector<int> diff;
    for (int j = 0; j < 26; j++) {
      if (partials[r][j] != partials[l-1][j]) {
        diff.push_back(j);
      }
    }
    assert(diff.size());
    if (diff.size() == 1) {
      cout << "No\n";
      continue;
    }
    if (diff.size() > 2) {
      cout << "Yes\n";
      continue;
    }
    cout << (s[l-1] == s[r-1] ? "No" : "Yes") << '\n';
  }
}