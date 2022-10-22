#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  string s;
  cin >> s;

  vector<int> cnt (26, 0);
  for (char c : s) {
    cnt[c - 'a']++;
  }

  int m = n / K;
  for (int i = 0; i < K; i++) {
    int cur = m;
    for (int j = 0; j < m; j++) {
      if (cnt[j] == 0) {
        cur = j;
        break;
      }
    }

    cout << (char) ('a' + cur);

    int need = m;
    for (int j = 0; j < cur; j++) {
      cnt[j]--;
      need--;
    }

    /*
    for (int j = 25; j >= 0; j--) {
      int take = min(cnt[j], need);
      cnt[j] -= take;
      need -= take;
    }
    */
  }
  cout << '\n';
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