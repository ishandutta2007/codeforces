#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

vector<int> f(100100);
vector<int> inv_f(100100);

int qpow(int a, int p) {
  if (p == 0)
      return 1;
  else if (p % 2 == 1)
      return (a * qpow(a, p - 1)) % mod;
  else {
      int h = qpow(a, p / 2);
    return (h * h) % mod;
  }
}

int inv(int a) {
  return qpow(a, mod - 2);
}

void solve() {
    int n;
    cin >> n;
    int groups = 0;
    int spaces = 0;
    int last = '0';
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == '0') {
            spaces++;
            last = '0';
        } else if (c == '1') {
            if (last == '0') {
                last = '1';
            } else {
                groups++;
                spaces++;
                last = '0';
            }
        }
    }
    // cout <<spaces << ' ' << groups << endl;
    cout << (((f[spaces] * inv_f[groups]) % mod) * inv_f[spaces - groups]) % mod << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    f[0] = 1;
    inv_f[0] = 1;
    for (int i = 1; i < f.size(); ++i) {
        f[i] = (f[i - 1] * i) % mod;
        inv_f[i] = inv(f[i]);
    }

    int t;
    cin >> t;
    while (t--)
        solve();
	return 0;
}