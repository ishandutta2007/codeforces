#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 2e5 + 5;

int cnt [MAX_N][26];

int main () {
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;

  int n = s.size();

  for (int i = 1; i <= n; i++) {
    cnt[i][s[i - 1] - 'a']++;
  }

  for (int i = 1; i <= n; i++) {
    for (int c = 0; c < 26; c++) {
      cnt[i][c] += cnt[i - 1][c];
    }
  }
  
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;r--;

    int diffc = 0;
    for (int c = 0; c < 26; c++) {
      if (cnt[r + 1][c] - cnt[l][c] != 0) {
        diffc++;
      }
    }

    if (l == r) {
      cout << "Yes" << '\n';
    } else if (s[l] != s[r]) {
      cout << "Yes" << '\n';
    } else if (diffc >= 3) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
}