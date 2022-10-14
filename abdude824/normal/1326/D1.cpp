/**
 *    author:  tourist
 *    created: 19.03.2020 17:42:13       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
}

template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> res = manacher(s);
    int match = 0;
    while (2 * match + 2 <= n && s[match] == s[n - 1 - match]) {
      match += 1;
    }
    int ans = 0;
    int afrom = 0;
    for (int z = 0; z <= 2 * n - 2; z++) {
      int i = (z + 1) >> 1;
      int j = z >> 1;
      if (i > j && res[z] == 0) {
        continue;
      }
      int from = i - res[z];
      int to = j + res[z];
      if (from < match) {
        int shift = match - from;
        from += shift;
        to -= shift;
      }
      if (to >= n - match) {
        int shift = to - (n - match) + 1;
        from += shift;
        to -= shift;
      }
      if (from != match && to != n - match - 1) {
        continue;
      }
      if (to - from + 1 > ans) {
        ans = to - from + 1;
        afrom = from;
      }
    }
    cout << (s.substr(0, match) + s.substr(afrom, ans) + s.substr(n - match, match)) << '\n';
  }
  return 0;
}