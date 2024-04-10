#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(all(a));

  if (n % 2 == 1) {
    cout << "NO\n";
    return;
  }

  vector<int> b;
  for (int i = 0; i < a.size() / 2; ++i) {
    b.push_back(a[i]);
    b.push_back(a[i + a.size() / 2]);
  }
  a = b;

  for (int i = 0; i < n; ++i) {
    bool is_min = (a[i] < a[(i + 1) % n] && a[i] < a[(i + n - 1) % n]);
    bool is_max = (a[i] > a[(i + 1) % n] && a[i] > a[(i + n - 1) % n]);
    if (!is_min && !is_max) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  for (int x : a) cout << x << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //solve(false);

  return 0;
}