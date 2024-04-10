#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

int st(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        int q = st(a, b / 2);
        return q * q % mod;
    }
    return a * st(a, b - 1) % mod;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, h;
    cin >> w >> h;
    cout << st(2, w + h) << '\n';
    return 0;
}