#include <iostream>

using namespace std;

const int MAX_N = 4e5 + 5;

bool is [MAX_N];

int get (int n, int dir) {
  int sta, fin;
  if (dir == 1) {
    sta = 1;
    fin = n + 1;
  } else {
    sta = n;
    fin = 0;
  }
  
  int buf = 0, ans = 0;
  for (int i = sta; i != fin; i += dir) {
    if (is[i]) {
      if (buf > 0) {
        buf--;
        ans++;
      }
    } else {
      buf++;
    }
  }
  return ans;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= 2 * n; i++) {
    is[i] = false;
  }

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    is[x] = true;
  }
  
  int mn = n - get(2 * n, 1);
  int mx = get(2 * n, -1);

  cout << mx - mn + 1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}