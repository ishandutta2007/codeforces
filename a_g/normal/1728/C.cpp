#include <bits/stdc++.h>
using namespace std;

int f(int x) {
  int ans = 0;
  while (x) {
    ans++;
    x /= 10;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int, greater<int>> freq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      freq[x]++;
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      freq[x]--;
    }
    int ans = 0;
    while (!freq.empty()) {
      auto it = freq.begin();
      if ((*it).second == 0) {
        freq.erase(it);
        continue;
      }
      int c = (*it).first;
      ans += abs((*it).second);
      freq[f(c)] += (*it).second;
      freq.erase(c);
    }
    cout << ans << '\n';
  }
}