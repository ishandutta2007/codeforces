#include <iostream>

using namespace std;

const int INF = 1e9 + 5;

struct Seg {
  int l = 0, r = 0, c = 0;
};

void solve () {
  int n;
  cin >> n;

  Seg mn, mx, mnmx;
  mn.l = INF;
  mx.r = 0;
  
  for (int i = 0; i < n; i++) {
    Seg cur;
    cin >> cur.l >> cur.r >> cur.c;

    if (cur.l < mn.l || cur.l == mn.l && cur.c < mn.c) {
      mn = cur;
    }

    if (cur.r > mx.r || cur.r == mx.r && cur.c < mx.c) {
      mx = cur;
    }

    bool mmxa = mnmx.l == mn.l && mnmx.r == mx.r;
    if (cur.l == mn.l && cur.r == mx.r) {
      if (mmxa) {
        if (cur.c < mnmx.c) {
          mnmx = cur;
        }
      } else {
        mnmx = cur;
      }
      mmxa = true;
    }

    int ans = mn.c + mx.c;
    if (mmxa) {
      ans = min(ans, mnmx.c);
    }

    cout << ans << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}