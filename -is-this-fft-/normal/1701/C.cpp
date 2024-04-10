#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

int cnt [MAX_N];

bool can (int n, int t) {
  ll need = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] >= t) {
      need += cnt[i] - t;
    } else {
      need -= (t - cnt[i]) / 2;
    }
  }

  return need <= 0;
}

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    cnt[x]++;
  }

  int ans = 0;
  for (int k = 1 << 20; k != 0; k /= 2) {
    if (!can(n, ans + k)) {
      ans += k;
    }
  }

  cout << ans + 1 << '\n';
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