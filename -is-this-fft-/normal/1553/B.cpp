#include <iostream>

using namespace std;

bool match (const string &s, const string &t, int m, int r, int l) {
  int ptr = 0;
  for (int i = m; i <= r; i++) {
    if (s[i] != t[ptr]) {
      return false;
    }
    
    ptr++;
  }

  for (int i = r - 1; i >= l; i--) {
    if (s[i] != t[ptr]) {
      return false;
    }

    ptr++;
  }

  if (ptr != (int) t.size()) {
    // should never happen
    return false;
  }

  return true;
}

void solve () {
  string s, t;
  cin >> s >> t;

  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int cur_len = 1 + j - i;
      int rem = (int) t.size() - cur_len;
      int k = j - rem;
      if (k < 0) continue;

      if (match(s, t, i, j, k)) {
        cout << "YES" << '\n';
        return;
      }
    }
  }

  cout << "NO" << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}