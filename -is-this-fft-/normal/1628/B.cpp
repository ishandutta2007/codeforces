#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool is_palin (const string &s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) {
      return false;
    }
  }
  return true;
}

void solve () {
  int n;
  cin >> n;

  vector<string> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  set<string> strs;
  set<string> pfs;
  for (auto s : arr) {
    if (is_palin(s)) {
      cout << "YES" << '\n';
      return;
    }

    if ((int) s.size() == 2) {
      string rev = {s[1], s[0]};
      if (strs.count(rev) || pfs.count(rev)) {
        cout << "YES" << '\n';
        return;
      }

      strs.insert(s);
    } else {
      string rev = {s[2], s[1], s[0]};
      string prev = {s[2], s[1]};
      if (strs.count(rev) || strs.count(prev)) {
        cout << "YES" << '\n';
        return;
      }

      strs.insert(s);
      string pf = {s[0], s[1]};
      pfs.insert(pf);
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