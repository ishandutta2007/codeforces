#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e3 + 5;

ll sq (ll x) {
  return x * x;
}

class Quadratic {
  ll a = 0, b = 0, c = 0;

public:
  ll eval (ll x) const {
    return a * sq(x) + b * x + c;
  }

  void addp (ll coef, ll x) {
    a += coef * 16;
    b -= coef * 8 * (4 * x - 2);
    c += coef * sq(4 * x - 2);
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  Quadratic X, Y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ll c;
      cin >> c;

      X.addp(c, i);
      Y.addp(c, j);
    }
  }

  pair<ll, pair<int, int>> ans = make_pair(X.eval(0) + Y.eval(0), make_pair(0, 0));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      ans = min(ans, make_pair(X.eval(i) + Y.eval(j), make_pair(i, j)));
    }
  }

  cout << ans.first << endl;
  cout << ans.second.first << " " << ans.second.second << endl;
}