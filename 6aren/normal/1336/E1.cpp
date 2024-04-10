#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MOD = 998244353;

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> basis;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int e : a) {
        for (int b : basis) {
            if ((e ^ b) < e) e ^= b; 
        }
        if (e > 0) {
            for (int &b : basis) {
                if ((e ^ b) < b) b ^= e;
            }
            basis.pb(e);
        }
    }
    sort(all(basis));
    // cout << basis.size() << endl;
    // for (int b : basis) {
    //     cout << bitset<7>(b) << '\n';
    // }
    for (int &b : basis) {
        for (int i = m - 1; i >= 0; i--) {
            if (bit(b, i)) {
                b ^= (1LL << i);
                break;
            }
        }
    }
    map<ii, int> mp;
    mp[{0, 0}] = 1;
    for (int b : basis) {
        vector<pair<ii, int>> to_add;
        for (auto it : mp) {
            int x = (it.x.x ^ b);
            int y = it.x.y + 1;
            to_add.pb({{x, y}, it.y});
        }
        for (auto it : to_add) {
            mp[it.x] = (mp[it.x] + it.y) % MOD;
        }
    }

    vector<int> ans(m + 1);
    for (auto it : mp) {
        ans[it.x.y + __builtin_popcountll(it.x.x)] += it.y;
    }

    int cplm = 1;
    for (int i = basis.size(); i < n; i++) cplm = (cplm * 2) % MOD;
    for (int e : ans) {
        e = (e % MOD * cplm) % MOD;
        cout << e << ' ';
    }
    return 0;
}