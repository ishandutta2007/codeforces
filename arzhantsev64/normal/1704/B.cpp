#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int minn = v[0];
    int maxx = v[0];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        minn = min(minn, v[i]);
        maxx = max(maxx, v[i]);
        if (maxx - minn > 2 * x) {
            ans++;
            minn = v[i];
            maxx = v[i];
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
         solve();

    return 0;
}

/*

7 4 8 1 6 10 3 5 2 9
*/