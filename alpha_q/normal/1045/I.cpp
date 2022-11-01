#include <bits/stdc++.h>

using namespace std;

#pragma gcc diagnostic warning "-std=c++11"

int n;
string s;
long long ans;
unordered_map <int, int> cnt;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  while (n--) {
    cin >> s;
    int mask = 0;
    for (char c : s) {
      mask ^= 1 << (c - 'a');
    }
    if (cnt.find(mask) != cnt.end()) {
      ans += cnt[mask];
    }
    for (int i = 0; i < 26; ++i) {
      if (cnt.find(mask ^ 1 << i) != cnt.end()) {
        ans += cnt[mask ^ 1 << i];
      }
    }
    ++cnt[mask];
  }
  cout << ans << '\n';
  return 0;
}