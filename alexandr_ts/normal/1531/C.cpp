#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

bool is_valid(int k, int tr, int n) {
  int mn = tr * tr;
  int mx = 2 * k * tr - tr * tr;
  if (n < mn || n > mx) return false;
  return (n - tr * tr) % 2 == 0;
}

vector<string> try_to_solve(int k, int tr, int n) {
  if (!is_valid(k, tr, n)) {
    return {};
  }
  string tmp;
  for (int i = 0; i < k; ++i) tmp += ".";
  vector<string> a(k, tmp);
  for (int i = 0; i < tr; ++i) {
    for (int j = 0; j < tr; ++j) {
      a[i][j] = 'o';
    }
  }
  int lft = (n - tr * tr) / 2;
  for (int i = tr; i < k; ++i) {
    int cnt = min(lft, tr);
    for (int j = 0; j < cnt; ++j) {
      a[i][j] = a[j][i] = 'o';
    }
    lft -= cnt;
  }

  for (int i = 0; i * 2 < k; ++i) {
    swap(a[i], a[k - 1 - i]);
  }
  return a;
}

void solve(int n) {
  if (n == 2) {
    cout << "-1" << endl;
    return;
  }

  for (int k = 1; k <= 12; ++k) {
    for (int tr = 1; tr <= k; ++tr) {
      auto rez = try_to_solve(k, tr, n);
      if (!rez.empty()) {
        cout << rez.size() << endl;
        for (auto x: rez) {
          cout << x << endl;
        }
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  /*
  for (int i = 1; i <= 100; ++i) {
    cout << i << endl;
    solve(i);
  }
  return 0;
  */

  int n;
  cin >> n;
  solve(n);

}