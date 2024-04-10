#include <bits/stdc++.h>

using namespace std;

using li = long long;

#define all(v) (v).begin(), (v).end()

void solve(bool read) {
  int n, k;
  cin >> n >> k;

  vector<li> a(n);
  for (li& x : a) {
    cin >> x;
  }
  li damage = accumulate(all(a), (li)0);
  for (int i = 0; i < n; ++i) {
    a[i] -= (n - i - 1);
  }

  //cout << "base: " << damage << "\n";
  //for (li x : a) cout << x << " "; cout << "\n";

  sort(all(a));
  reverse(all(a));

  li min_damage = damage;
  for (int i = 0; i < k; ++i) {
    damage -= a[i];
    min_damage = min(min_damage, damage - i * (li)(i + 1) / 2);
  }

  cout << min_damage << "\n";
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}