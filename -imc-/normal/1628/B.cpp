#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read = true) {
  int n;
  cin >> n;

  vector<string> v;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  for (size_t i = 0; i < 2; ++i) {
    set<string> ss;
    for (auto& it : v) {
      ss.insert(it);

      if (it.size() == 1) {
        cout << "YES\n";
        return;
      }

      auto x = it;
      reverse(all(x));
      if (ss.count(x)) {
        cout << "YES\n";
        return;
      }

      if (it.size() == 3) {
        x.pop_back();
        if (ss.count(x)) {
          cout << "YES\n";
          return;
        }
      }
    }

    reverse(all(v));
    for (auto& it : v) {
      reverse(all(it));
    }
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}