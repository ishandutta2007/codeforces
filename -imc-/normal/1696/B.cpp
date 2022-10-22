#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n;
  cin >> n;

  vector<int> a(n);
  int s = 0;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];

    if (a[i]) {
      ++cur;
    } else {
      if (cur) {
        ++s;
        cur = 0;
      }
    }
  }
  if (cur) {
    ++s;
  }

  if (s == 0) {
    cout << "0\n";
  } else if (s == 1) {
    cout << "1\n";
  } else {
    cout << "2\n";
  }
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