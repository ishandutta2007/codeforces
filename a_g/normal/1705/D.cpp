#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (s[0] != t[0] || s[n-1] != t[n-1]) {
      cout << "-1\n";
      continue;
    }

    vector<pair<int, int>> groups_s, groups_t;
    for (int i = 0; i < n;) {
      if (s[i] == '1') {
        int r = i;
        while (r+1 < n && s[r+1] == '1') r++;
        groups_s.emplace_back(i, r);
        i = r+1;
      }
      else i++;
    }

    for (int i = 0; i < n;) {
      if (t[i] == '1') {
        int r = i;
        while (r+1 < n && t[r+1] == '1') r++;
        groups_t.emplace_back(i, r);
        i = r+1;
      }
      else i++;
    }
    if (groups_s.size() != groups_t.size()) {
      cout << "-1\n";
      continue;
    }

    long long ans = 0;
    for (int i = 0; i < (int)groups_s.size(); i++) {
      int l1 = groups_s[i].first;
      int r1 = groups_s[i].second;
      int l2 = groups_t[i].first;
      int r2 = groups_t[i].second;
      if (r1 < l2) {
        ans += (r2-l1+l2-r1);
      }
      else if (r2 < l1) {
        ans += (r1-l2+l1-r2);
      }
      else {
        ans += max(r2, r1)-min(l1, l2)-min(r1, r2)+max(l1, l2);
      }
    }
    cout << ans << '\n';
  }
}