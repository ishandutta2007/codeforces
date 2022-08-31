#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;
const int MAX_LG = 19;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll arr [MAX_N];
ll sparse [MAX_LG][MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  n--;
  for (int i = 0; i < n; i++) {
    sparse[0][i] = abs(arr[i + 1] - arr[i]);
  }

  for (int k = 1; k < MAX_LG; k++) {
    for (int i = 0; i < n; i++) {
      if (i + (1 << k) > n) {
        break;
      }

      sparse[k][i] = gcd(sparse[k - 1][i], sparse[k - 1][i + (1 << (k - 1))]);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = i;
    ll cursp = 0;
    for (int k = MAX_LG - 1; k >= 0; k--) {
      if (cur + (1 << k) > n) {
        continue;
      }

      auto nxt = gcd(cursp, sparse[k][cur]);
      if (nxt != 1) {
        cur += 1 << k;
        cursp = nxt;
      }
    }

    ans = max(ans, cur - i);
  }

  cout << 1 + ans << '\n';
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