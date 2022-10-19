#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;
const int A = 26;

int m, n;
string s;

void read() {
  cin >> m >> s;
  n = s.length();
}


void kill() {
  string ans = "";

  for (int k = 0; k < A; ++k) {
    char c = 'a' + k;
    int last = -1;
    bool good = true;
    int x = -1;

    int tot = 0;
    for (char ch : s)
      if (ch == c)
        ++tot;

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
      if (s[i] == c)
        x = i;

      if (s[i] < c)
        last = i;

      if (last + m == i) {
        if (x <= last) {
          good = false;
          break;
        } else {
          cnt++;
          last = x;
        }
      }
    }

    if (good) {
      ans = ans + string(cnt, c);
      cout << ans << "\n";
      return;
    } else {
      ans = ans + string(tot, c);
    }
  }

  assert(false);
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}