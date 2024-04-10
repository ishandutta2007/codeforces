#include <iostream>
#include <cassert>

using namespace std;

typedef long long ll;

ll cfrac (ll p, ll q) {
  return (p + q - 1) / q;
}

const int MAX_N = 205;
const int MAX_M = 1e5 + 5;
const int D = 100000;

int fst [MAX_N][MAX_M];
int ans [MAX_M];

ll op (int t, ll k, ll xp) {
  switch (t) {
  case 1:
    return k + cfrac(xp, D);
  case 2:
    return cfrac(k * xp, D);
  }
  assert(false);
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= m; i++) {
    ans[i] = MAX_N;
  }
  
  for (int k = 0; k <= m; k++) {
    fst[0][k] = MAX_M;
  }
  fst[0][0] = 0;
  
  for (int i = 1; i <= n; i++) {
    ll t, xp, y;
    cin >> t >> xp >> y;

    for (int k = 0; k <= m; k++) {
      fst[i][k] = MAX_M;
    }
    
    for (int k = 0; k <= m; k++) {
      if (fst[i - 1][k] < MAX_M) {
        fst[i][k] = 0;
      }

      ll nxt = op(t, k, xp);
      if (nxt <= m) {
        fst[i][nxt] = min(fst[i][nxt], fst[i][k] + 1);
      }
    }

    for (int k = 0; k <= m; k++) {
      if (fst[i][k] > y) {
        fst[i][k] = MAX_M;
      } else {
        ans[k] = min(ans[k], i);
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    if (ans[i] == MAX_N) {
      cout << -1 << " ";
    } else {
      cout << ans[i] << " ";
    }
  }
  cout << endl;
}