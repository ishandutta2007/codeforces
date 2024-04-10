#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool can (vector<ll> heaps, int mn) {
  int n = heaps.size();
  vector<ll> add (n, 0);
  for (int i = n - 1; i >= 2; i--) {
    if (heaps[i] + add[i] < mn) {
      return false;
    }

    ll d = min((heaps[i] + add[i] - mn) / 3, heaps[i] / 3);
    add[i - 1] += d;
    add[i - 2] += 2 * d;
  }

  if (heaps[1] + add[1] < mn) return false;
  if (heaps[0] + add[0] < mn) return false;
  return true;
}

void solve () {
  int n;
  cin >> n;

  vector<ll> heaps (n);
  for (int i = 0; i < n; i++) {
    cin >> heaps[i];
  }

  int ans = 0;
  for (int k = 1 << 29; k != 0; k /= 2) {
    if (can(heaps, ans + k)) {
      ans += k;
    }
  }

  cout << ans << '\n';
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