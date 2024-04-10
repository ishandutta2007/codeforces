#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int __int128_t
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
    ll n, m;
    cin >> n >> m;

    int minn = -1;
    int maxx = -1;
    int ind_max = -1;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            cur += (__int128_t)j * (__int128_t)x;
        }

        if (minn == -1 || minn > cur)
            minn = cur;
        if (maxx == -1 || maxx < cur) {
            maxx = cur;
            ind_max = i;
        }
    }
    cout << (ll)ind_max + 1 << ' ' << (ll)(maxx - minn) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
         solve();

    return 0;
}

/*

7 4 8 1 6 10 3 5 2 9
*/