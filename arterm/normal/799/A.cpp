#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

#define int ll

int n, t, k, d;

void read() {
    cin >> n >> t >> k >> d;
}

void kill() {
    int A = (n + k - 1) / k * t;

    int l = 0, r = 2e6;

    while (l < r) {
        int x = (l + r) / 2;
        int first = (x / t) * k;
        int second = (max(0ll, x - d) / t) * k;
        if (first + second >= n)
            r = x;
        else
            l = x + 1;
    }

    if (l < A)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}