#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  string s;
  cin >> s;

  vector<int> cnt (128, 0);
  for (char c : s) {
    cnt[c]++;
  }

  vector<char> active;
  for (char c = 'a'; c <= 'z'; c++) {
    if (cnt[c] > 0) {
      active.push_back(c);
    }
  }

  if (active.size() == 1) {
    cout << s << '\n';
    return;
  }
  
  for (char c : active) {
    if (cnt[c] == 1) {
      cout << c;
      cnt[c]--;

      for (char d : active) {
        for (int i = 0; i < cnt[d]; i++) {
          cout << d;
        }
      }
      cout << '\n';
      return;
    }
  }

  int n = s.size();
  // can't solve with 1, must solve with 2
  if (2 * (cnt[active[0]] - 2) <= n - 2) {
    // aa b+ a b+ a b+ a
    cout << active[0] << active[0];
    cnt[active[0]] -= 2;

    vector<char> stock;
    for (char c = 'a'; c <= 'z'; c++) {
      if (c != active[0]) {
        for (int i = 0; i < cnt[c]; i++) {
          stock.push_back(c);
        }
      }
    }
    reverse(stock.begin(), stock.end());

    while (!stock.empty()) {
      cout << stock.back();
      stock.pop_back();

      if (cnt[active[0]] > 0) {
        cout << active[0];
        cnt[active[0]]--;
      }
    }
    cout << '\n';
    return;
  }

  if (active.size() == 2) {
    // ab bbbbbbaaaaaa
    cout << active[0] << active[1];
    cnt[active[0]]--;
    cnt[active[1]]--;

    for (int i = 0; i < cnt[active[1]]; i++) {
      cout << active[1];
    }
    for (int i = 0; i < cnt[active[0]]; i++) {
      cout << active[0];
    }
    cout << '\n';
  } else {
    // ab aaaacbbccc
    cout << active[0] << active[1];
    cnt[active[0]]--;
    cnt[active[1]]--;

    for (int i = 0; i < cnt[active[0]]; i++) {
      cout << active[0];
    }
    cout << active[2];
    cnt[active[2]]--;

    for (int k = 1; k < (int) active.size(); k++) {
      for (int i = 0; i < cnt[active[k]]; i++) {
        cout << active[k];
      }
    }
    cout << '\n';
  }
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