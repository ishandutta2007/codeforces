#include<bits/stdc++.h>

using namespace std;

#define int long long
int mod = 998244353;

int st(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        int c = st(x, y / 2);
        return c * c % mod;
    }
    return x * st(x, y - 1) % mod;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int cnt = st(r - l + 1, n * m);
    if (n * m % 2 == 1) {
        cout << cnt << '\n';
        exit(0);
    }
    if ((r - l + 1) % 2 == 1) cnt++;
    cout << cnt * st(2, mod - 2) % mod << '\n';
    return 0;
}