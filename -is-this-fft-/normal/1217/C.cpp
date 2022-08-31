#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int len (int x) {
  return 32 - __builtin_clz(x);
}

void solve () {
  string s;
  cin >> s;

  int n = s.size();
  
  vector<pair<int, int>> zeros; // <length, endpos>
  int zc = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      zc++;
    } else {
      zeros.push_back(make_pair(zc, i));
      zc = 0;
    }
  }

  sort(zeros.begin(), zeros.end(), greater<pair<int, int>> ());

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int need = i - len(i);
    for (auto pr : zeros) {
      if (pr.first < need) {
        break;
      }

      int pos = pr.second;
      if (len(i) <= n - pos) {
        int cur = 0;
        for (int j = pos; j < pos + len(i); j++) {
          cur *= 2;
          cur += s[j] - '0';
        }
        if (cur == i) ans++;
      }
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}