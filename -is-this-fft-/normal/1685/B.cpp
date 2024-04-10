#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve () {
  int a, b, ab, ba;
  cin >> a >> b >> ab >> ba;

  vector<int> neu;
  vector<int> abb;
  vector<int> bab;

  string s;
  cin >> s;

  int na = 0, nb = 0;
  for (char c : s) {
    if (c == 'A') na++;
    else nb++;
  }

  if (na != a + ab + ba || nb != b + ab + ba) {
    cout << "NO" << '\n';
    return;
  }
  
  int len = 0;
  for (int i = 0; i <= (int) s.size(); i++) {
    if (i == (int) s.size() || i != 0 && s[i] == s[i - 1]) {
      if (len % 2 == 0) {
        // biased
        if (s[i - 1] == 'B') {
          abb.push_back(len / 2);
        } else {
          bab.push_back(len / 2);
        }
      } else {
        neu.push_back(len / 2);
      }
      
      len = 0;
    }
    len++;
  }

  sort(abb.begin(), abb.end());
  sort(bab.begin(), bab.end());
  
  for (auto cur : abb) {
    int take = min(cur, ab);
    cur -= take;
    ab -= take;

    take = min(max(cur - 1, 0), ba);
    cur -= take;
    ba -= take;
  }

  for (auto cur : neu) {
    int take = min(cur, ab);
    cur -= take;
    ab -= take;

    take = min(cur, ba);
    cur -= take;
    ba -= take;
  }
  
  for (auto cur : bab) {
    int take = min(cur, ba);
    cur -= take;
    ba -= take;

    take = min(max(cur - 1, 0), ab);
    cur -= take;
    ab -= take;
  }

  if (ab != 0 || ba != 0) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
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