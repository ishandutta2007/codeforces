#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    const ll INFLL = 1e18;
    const int INFI = 1e9;
    const int d[2][4] = {{0, 0, 1, 1}, {0, 1, 0, 1}};
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        array<array<ll, 2>, 4> p;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> p[i][j];
        auto check_direction = [&](int t, ll v, ll s) -> ll {
            ll ret = 0;
            for (int i = 0; i < 4; ++i)
                ret += abs(p[i][t] - (v + s * d[t][i]));
            return ret;
        };
        vector<ll> X, Y;
        auto check = [&](ll s) -> ll {
            ll res = INFLL;
            X.clear();
            Y.clear();
            for (int i = 0; i < 4; ++i)
                X.push_back(p[i][0]), X.push_back(p[i][0] - s);
            for (int i = 0; i < 4; ++i)
                Y.push_back(p[i][1]), Y.push_back(p[i][1] - s);
            sort(p.begin(), p.end());
            do {
                ll hori = INFLL;
                ll vert = INFLL;
                for (ll x : X) 
                    hori = min(hori, check_direction(0, x, s));
                for (ll y : Y) 
                    vert = min(vert, check_direction(1, y, s));
                res = min(res, hori + vert);
            } while(next_permutation(p.begin(), p.end()));
            return res;
        };
        ll ans = INFLL;
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                ans = min(ans, check(abs(p[i][0] - p[j][0])));
                ans = min(ans, check(abs(p[i][1] - p[j][1])));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}