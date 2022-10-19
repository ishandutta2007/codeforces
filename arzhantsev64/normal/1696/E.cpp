#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 1e9 + 7;

int qpow(int a, int p) {
    if (p == 0)
        return 1;
    else if (p % 2 == 1) {
        return (a * qpow(a, p - 1)) % mod;
    } else {
        int h = qpow(a, p / 2);
        return (h * h) % mod;
    }
}

int inv(int a) {
    return qpow(a, mod - 2);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> f(600000);
    vector<int> inv_f(600000);
    f[0] = 1;
    inv_f[0] = 1;
    for (int i = 1; i < f.size(); ++i) {
        f[i] = (i * f[i - 1]) % mod;
        inv_f[i] = inv(f[i]);
    }


    int ans = 0;
    int last = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; ++i) {
        int x;
        cin >> x;

        if (x != 0)
            ans = (ans + ((((f[x + i] * inv_f[i + 1]) % mod) * inv_f[x - 1]) % mod)) % mod;
        // cout << ans << endl;
    }

    cout << ans << '\n';


    return 0;
}



/*

_1+k^1

*/