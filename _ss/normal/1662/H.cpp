#include <bits/stdc++.h>
using namespace std;

vector<int> candidates, ans;

void find_div(int x) {
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      candidates.emplace_back(i);
      candidates.emplace_back(x / i);
    }
  }
}

void solve() {
  int w, l;
  cin >> w >> l;

  candidates.clear();
  ans.clear();
  find_div(w);
  find_div(w - 1);
  find_div(l);
  find_div(l - 1);

  sort(candidates.begin(), candidates.end());
  candidates.resize(unique(candidates.begin(), candidates.end()) - candidates.begin());

  for (int x : candidates) {
    vector<int> a = {w, l, w, l - 1};
    bool ok = true;
    for (int i = 0; i < 4; ++i) {
      if (a[i] % x > 1) {
        ok = false;
        break;
      }
      if (a[i] % x == 0) {
        if (i + 1 < 4) {
          --a[i + 1];
        }
      } else {
        if (i == 3) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      ans.emplace_back(x);
      continue;
    }

    a = {l, w, l, w - 1};
    ok = true;
    for (int i = 0; i < 4; ++i) {
      if (a[i] % x > 1) {
        ok = false;
        break;
      }
      if (a[i] % x == 0) {
        if (i + 1 < 4) {
          --a[i + 1];
        }
      } else {
        if (i == 3) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      ans.emplace_back(x);
      continue;
    }
  }

  cout << ans.size();
  for (int x : ans) {
    cout << ' ' << x;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}