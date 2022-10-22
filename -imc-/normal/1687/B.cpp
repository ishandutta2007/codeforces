#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> l(m);
  for (int i = 0; i < m; ++i) {
    l[i].second = i;

    string s(m, '0');
    s[i] = '1';
    cout << "? " << s << endl;
    cin >> l[i].first;
  }
  sort(all(l));

  int old_res = 0;
  string s(m, '0');
  for (int i = 0; i < m; ++i) {
    s[l[i].second] = '1';

    cout << "? " << s << endl;
    int res;
    cin >> res;

    if (res - old_res == l[i].first) {
      old_res = res;
      continue;
    }

    s[l[i].second] = '0';
  }

  cout << "! " << old_res << endl;
}

int main() {
  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //while (true) solve(false);

  return 0;
}