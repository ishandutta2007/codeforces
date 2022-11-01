#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  void solve_brute() {
    for (int n = 3; n <= 10; ++n) {
      cout << n << " ";
      for (int mx = n + 1; mx < 100; ++mx) {
        if (f(n, mx)) {
          cout << mx << endl;
          break;
        }
      }
    }
  }

  void solve(int n) {
    if (n <= 2) {
      cout << -1 << endl;
      return;
    }

    int answer = 1;
    while (answer < n) {
      answer *= 2;
    }

    a.resize(n);
    iota(a.begin(), a.end(), 1);

    solve_impl(0, n - 1);

    sort(a.begin(), a.end());


    int zero_i = -1;
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i] == a[i + 1]) {
        zero_i = i;
        break;
      }
    }
    assert(zero_i != -1);
    step(zero_i + 1, zero_i);

    //for (auto e : a) cout << e << " ";cout << endl;

    for (int i = 0; i < n; ++i) {
      if (a[i] == answer || a[i] == 0) {
        continue;
      }
      while (a[i] < answer) {
        step(i, zero_i);
        step(i, zero_i);
      }
    }

    int other_i = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != 0) {
        other_i = i;
        break;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        step(i, other_i);
      }
    }


    /*
    for (auto e : a) {
      if (e != answer) {
        cout << n << endl;
        for (auto e : a) cout << e << " ";cout << endl;
      }
      assert(e == answer);
    }
    */

    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
      cout << x << " " << y << "\n";
    }

  }

private:
  vector<int> a;
  vector<pair<int, int>> ans;

  void step(int i, int j) {
    ans.push_back({a[i], a[j]});
    a[i] = a[i] + a[j];
    a[j] = abs(a[i] - 2 * a[j]);
  }

  void solve_impl(int l, int r) {
    // cout << l << " " << r << ", ";
    //for (int i = l; i <= r; ++i) cout << a[i] << " ";cout << endl;
    int n = r - l + 1;
    if (n <= 2) {
      return;
    }
    if ((n & (n - 1)) == 0) {
      solve_impl(l, r - 1);
      return;
    }

    int p = 1;
    while (p * 2 <= n) {
      p *= 2;
    }

    for (int i = l + p; i <= r; ++i) {
      int i1 = i - (l + p - 1);
      int j = l + (p - 1 - i1);
      step(i, j);
    }
    int next_r = 2 * (l + p - 1) - (r + 1);
    solve_impl(l, next_r);
    reverse(a.begin() + next_r + 1, a.begin() + l + p - 1);
    solve_impl(next_r + 1, l + p - 2);
  }

  bool f(int n, int mx) {
    mt19937 g;
    for (int it = 0; it < 100000; ++it) {
      vector<int> p(n);
      for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
      }
      while (true) {
        bool ok = false;
        for (int i = 0; i < n; ++i) {
          for (int j = i + 1; j < n; ++j) {
            if (p[i] + p[j] <= mx)
              ok = true;
          }
        }
        if (!ok) break;
        int i = g() % n;
        int j = g() % n;
        while (i == j || p[i] + p[j] > mx) {
          i = g() % n;
          j = g() % n;
        }
        int xx = p[i] + p[j];
        int yy = abs(p[i] - p[j]);
        p[i] = xx;
        p[j] = yy;
      }
      if (*min_element(p.begin(), p.end()) == mx && *max_element(p.begin(), p.end()) == mx) {
        return true;
      }
    }
    return false;
  }

};

void stress() {
  for (int n = 2; n <= 100; ++n) {
    Solver{}.solve(n);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

//  stress();

  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Solver{}.solve(n);
  }
}