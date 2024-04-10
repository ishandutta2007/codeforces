#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 207;

void upd(int &x, int &y, char c) {
  if (c == 'U')
    ++x;
  else if (c == 'D')
    --x;
  else if (c == 'L')
    ++y;
  else if (c == 'R')
    --y;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  int n;
  int ans = 0;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n; ++i) {
    int x = 0, y = 0;
    for (int j = i; j < n; ++j) {
      upd(x, y, s[j]);
      if (x == 0 && y == 0)
        ans++;
    }
  }

  cout << ans << endl;
}