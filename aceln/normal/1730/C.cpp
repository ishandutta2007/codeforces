#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length() + 2;
    s = "0" + s + "a";

    vector<pair<int, int>> mn(n);
    vector<int> used(n);
    mn[n - 1] = {100, -1};
    for (int i = n - 2; i >= 0; i--)
      mn[i] = min(mn[i + 1], {s[i + 1] - '0', i + 1});

    int idx = -1;
    priority_queue<int, vector<int>, greater<>> pq;
    string ans;

    ans += string(1, mn[0].first + '0');
    idx = mn[0].second;
    for (int i = 1; i < idx; i++)
      pq.push(min(9, s[i] - '0' + 1));
    while (ans.length() < n - 2) {
      int ch1 = mn[idx].first;
      int ch2 = (pq.size() ? pq.top() : 100);
      if (ch1 <= ch2) {
        ans += string(1, ch1 + '0');
        for (int i = idx + 1; i < mn[idx].second; i++)
          pq.push(min(9, s[i] - '0' + 1));
        idx = mn[idx].second;
      } else {
        ans += string(1, ch2 + '0');
        pq.pop();
      }
    }
    cout << ans << '\n';
  }
}