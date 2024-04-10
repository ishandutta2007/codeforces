#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        int sq = (int) sqrt(n / 2);
        if ((sq - 1) * (sq - 1) == n / 2) {
            sq--;
        }
        if ((sq + 1) * (sq + 1) == n / 2) {
            sq++;
        }
        if ((sq - 1) * (sq - 1) == n / 2) {
            sq--;
        }
        if ((sq + 1) * (sq + 1) == n / 2) {
            sq++;
        }
        if (sq * sq == n / 2) {
            cout << "YES" << endl;
            return;
        }
    }
    if (n % 4 == 0) {
        int sq = (int) sqrt(n / 4);
        if ((sq - 1) * (sq - 1) == n / 4) {
            sq--;
        }
        if ((sq + 1) * (sq + 1) == n / 4) {
            sq++;
        }
        if ((sq - 1) * (sq - 1) == n / 4) {
            sq--;
        }
        if ((sq + 1) * (sq + 1) == n / 4) {
            sq++;
        }
        if (sq * sq == n / 4) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}