#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int R = 20000;

void no() {
  cout << "NO\n";
  exit(0);
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;

  cin >> n;

  int cur = 0;

  for (int i = 0; i < n; ++i) {
    int x;
    string s;
    cin >> x >> s;
    if (s == "North") {
      cur -= x;
      if (cur < 0)
        no();
    } else if (s == "South") {
      cur += x;
      if (cur > R)
        no();
    } else {
      if (cur == 0 || cur == R)
        no();
    }
  }

  if (cur != 0)
    no();

  cout << "YES\n";

}