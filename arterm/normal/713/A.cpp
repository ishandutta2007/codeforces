#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 20;
const int N = 1 << M;

int d[N];

void add(ll x, int val) {
  int mask = 0;
  for (int i = 0; i < M; ++i) {
    mask = (mask << 1) | (x % 2);
    x /= 10;
  }
  d[mask] += val;
}
  

void kill() {
  int q;
  cin >> q;
  while (q--) {
    char ch;
    cin >> ch;

    if (ch != '?') {
      int val = ch == '+' ? 1 : -1;
      ll x;
      cin >> x;
      add(x, val);
    } else {
      string s;
      cin >> s;

      s = string(M - s.length(), '0') + s;
      reverse(s.begin(), s.end());

      int mask = 0;
      for (char c : s)
        mask = (mask << 1) | (c == '1');

      cout << d[mask] << "\n";
    }
  }
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  kill();
  return 0;
}