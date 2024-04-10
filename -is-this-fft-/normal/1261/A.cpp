#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int n, K;
  string s;
  cin >> n >> K >> s;

  string t = "";
  for (int i = 0; i < K - 1; i++) {
    t += "()";
  }
  for (int i = 0; i < (n - 2 * (K - 1)) / 2; i++) {
    t += '(';
  }
  for (int i = 0; i < (n - 2 * (K - 1)) / 2; i++) {
    t += ')';
  }

  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      int r = -1;
      for (int j = i + 1; j < n; j++) {
        if (s[j] == t[i]) {
          r = j;
          break;
        }
      }

      ans.push_back(make_pair(i + 1, r + 1));
      reverse(s.begin() + i, s.begin() + r + 1);
    }
  }

  cout << (int) ans.size() << '\n';
  for (auto pr : ans) {
    cout << pr.first << " " << pr.second << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}