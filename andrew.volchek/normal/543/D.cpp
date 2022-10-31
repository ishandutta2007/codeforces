#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

#define ll long long
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

const int maxn = 200005;
const ll mod = 1000000007;

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return bpow(x, mod - 2);
}

map<pair<int, int>, ll> ans;
vector<int> g[maxn];
vector<int> order;

ll dfs(int v, int p) {
    order.pb(v);
    ll &res = ans[mp(v, p)] = 1;
    for (int to : g[v]) {
        if (to == p)
            continue;
        res = res * (2LL + dfs(to, v)) % mod;
    }

    res = (res + mod - 1) % mod;

    return res;
}


int main() {
    //freopen("a.in", "r", stdin);

    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        g[i].pb(p);
        g[p].pb(i);
    }

    dfs(1, -1);

    for (int v : order) {
        ll res = 1;
        int zr = 0;
        for (int to : g[v]) {
            ll c = (2LL + ans[mp(to, v)]) % mod;
            if (!c) {
                zr++;
            } else {
                res = (res * c) % mod;
            }
        }

        ans[mp(v, -1)] = (res * (zr ? 0 : 1) + mod - 1) % mod;

        for (int to : g[v]) {
            ll c = (2LL + ans[mp(to, v)]) % mod;
            ll cres = res;
            int czr = zr;
            if (!c) {
                czr--;
            } else {
                cres = cres * inv(c) % mod;
            }
            ans[mp(v, to)] = (cres * (czr ? 0 : 1) + mod - 1) % mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }

        printf("%d", int((ans[mp(i, -1)] + 1) % mod));
    }

    return 0;
}