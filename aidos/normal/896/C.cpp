#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef long long ll;
ll n, m, seed, vmax;

ll rnd() {
    ll ret = seed;
    seed = (seed * 1ll * 7 + 13) % 1000000007;
    return ret;
}
ll binpow(ll x, ll y, ll mod) {
    if(y == 0) return 1;
    if(y % 2 == 0) {
        return binpow(x * x % mod, y/2, mod);
    }
    return binpow(x, y-1, mod) * x % mod;
}
int main(){
    cin >> n >> m >> seed >> vmax;
    vector<pair<int, ll> >a;
    for(int i = 1; i <= n; i++) {
        a.push_back(make_pair(1, rnd() % vmax + 1));
    }
    for(int i = 1; i <= m; i++) {
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        if (l > r){
            swap(l, r);
        }
        int x;
        if (op == 3) {
            x = (rnd() % (r - l + 1)) +1;
        }else {
            x = (rnd()%vmax) +1;
        }
        int y;
        if (op == 4) {
            y = (rnd() % vmax) + 1;
        }
        vector< pair<ll, ll> > c, d, e;
        for(auto x: a) {
            if(r <= 0) {
                e.push_back(x);
                continue;
            }
            if(x.first < l) {
                l -= x.first;
                r -= x.first;
                c.push_back(x);
                continue;
            }
            if(l > 1) {
                c.push_back({l-1, x.second});
            }
            if(x.first <= r) {
                d.push_back({x.first - l + 1, x.second});
                r -= x.first;
                l = 1;
                continue;
            }
            d.push_back({r-l+1, x.second});
            e.push_back({x.first - r, x.second});
            r=0;
        }

        a.clear();
        for(auto x: c) a.push_back(x);
        if(op == 1) {
            for(int i = 0; i < d.size(); i++) {
                d[i].second += x;
            }
        } else if(op == 2) {
            int s=0;
            for(int i = 0; i < d.size(); i++) {
                s += d[i].first;
            }
            d.clear();
            d.push_back({s, x});
        } else if(op == 3) {
            vector< pair<ll, ll> > f;
            for(auto x: d) {
                f.push_back({x.second, x.first});
            }
            sort(f.begin(), f.end());
            for(int i = 0; i < f.size(); i++) {
                if(f[i].second >= x) {
                    cout << f[i].first << "\n";
                    break;
                }
                x -= f[i].second;
            }
        } else {
            ll ans = 0;
            for(auto g: d) {
                ans = (ans + binpow(g.second % y, x, y) * g.first) % y;
            }
            cout << ans << "\n";
        }

        for(auto x: d) a.push_back(x);
        for(auto x: e) a.push_back(x);


    }
}