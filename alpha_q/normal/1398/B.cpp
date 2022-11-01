#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    int n = s.size();
    vector <int> vec;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') continue;
      int j = i, len = 0;
      while (j < n and s[j] == '1') ++j, ++len;
      vec.emplace_back(len), i = j;
    }
    sort(vec.begin(), vec.end(), greater <int> ());
    int ans = 0;
    for (int i = 0; i < vec.size(); i += 2) ans += vec[i];
    cout << ans << '\n';
  }
  return 0;
}