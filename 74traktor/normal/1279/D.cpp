#include<bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

int go[1000005];
int k[1000005];
vector < int > t[1000005];

int st(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        int c = st(a, b / 2);
        return c * c % mod;
    }
    return a * st(a, b - 1) % mod;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x = 0, xx, f = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j) {
            cin >> xx;
            go[xx]++;
            t[i].push_back(xx);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int good = 0, y = k[i] * n % mod;
        for (auto key : t[i]) {
            good += go[key];
            good %= mod;
        }
        f += good * st(y, mod - 2);
        f %= mod;
    }
    f %= mod;
    cout << f * st(n, mod - 2) % mod;
    return 0;
}