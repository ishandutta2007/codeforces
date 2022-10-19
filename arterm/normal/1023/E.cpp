#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 505;

int n;

bool ask(int x, int y, int tx, int ty) {
  cout << "? " << x << " " << y << " " << tx << " " << ty << endl;
  string res;
  cin >> res;
  return res == "YES";
}

int main() {
#ifdef LOCAL
  //assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  cin >> n;

  int x = 1, y = 1;

  string l, r;
  
  while (x + y < n + 1) {
    if (x + 1 <= n && ask(x + 1, y, n, n)) {
      l.push_back('D');
      ++x;
    } else {
      l.push_back('R');
      ++y;
    }
  }

  x = n, y = n;
  while (x + y > (n + 1)) {
    if (y - 1 >= 1 && ask(1, 1, x, y - 1)) {
      --y;
      r.push_back('R');
    } else {
      --x;
      r.push_back('D');
    }
  }

  reverse(all(r));

  cout << "! " << (l + r) << endl;
}