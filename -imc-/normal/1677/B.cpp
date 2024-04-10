#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vector<li> row_ans(n * m), col_ans(n * m);

  vector<int> pref(n * m);
  for (int i = 0; i < n * m; ++i) {
    pref[i] = (i ? pref[i - 1] : 0) + (s[i] == '1');
  }

  auto sum = [&](int l, int r) {
    return pref[min<int>(r, pref.size() - 1)] - (l > 0 && l < n * m ? pref[l - 1] : 0);
  };

  for (int i = 0; i < n * m; ++i) {
    if (i >= m) {
      int L = (i + 1) - m;
      row_ans[i] = (i >= m ? row_ans[i - m] : 0) + (sum(L, L + m - 1) > 0);
    } else {
      row_ans[i] = sum(0, i) > 0;
    }
  }

  deque<int> cols;
  for (int i = 0; i < m; ++i) {
    cols.push_back(0);
  }

  int num_cols = 0;

  auto alter = [&](int val, int sign) {
    num_cols += (val > 0 ? 1 : 0) * sign;
  };

  for (int i = 0; i < n * m; ++i) {
    int x = cols.back();
    alter(x, -1);
    cols.pop_back();

    x += (s[i] - '0');
    alter(x, 1);
    cols.push_front(x);

    col_ans[i] = num_cols;
  }

  for (int i = 0; i < n * m; ++i) {
    cout << col_ans[i] + row_ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //while (true) solve(false);

  return 0;
}