#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 3e5 + 5;

ll K [MAX_N];
ll cost [MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    cin >> K[i];
  }
  sort(K + 1, K + n + 1);

  for (int i = 1; i <= m; i++) {
    cin >> cost[i];
  }

  ll cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += cost[K[i]];
  }

  ll ans = cur;
  int ptr = 1;
  for (int i = n; i >= 1; i--) {
    if (ptr <= m) {
      cur -= cost[K[i]];
      cur += cost[ptr];
      ptr++;
    }
    ans = min(ans, cur);
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}