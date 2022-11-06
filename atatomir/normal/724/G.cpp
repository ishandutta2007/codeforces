#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 300011
#define mod 1000000007
#define lim 62

ll n, m, i;
ll x, y, z;
vector< pair<ll, ll> > list[maxN];

vector<ll> xors, done;
bool us[maxN];
ll lvl[maxN];

ll cnt[77];
ll cnt_way[77];
vector<ll> now_xors;

ll circles, ways;
ll ans;

ll last[maxN];


void dfs(ll node, ll act) {
    now_xors.pb(act);
    last[node] = act;

    us[node] = true;
    for (auto to : list[node]) {
        if (!us[to.first]) {
            lvl[to.first] = lvl[node] + 1;
            dfs(to.first, act ^ to.second);
        } else {
            if (lvl[to.first] >= lvl[node] - 1) continue;
            xors.pb(act ^ to.second ^ last[to.first]);
        }
    }
}

void clean() {
    ll i, j, k;

    i = 0; j = 0;
    while (i < xors.size() && j <= lim) {
        ll bit = (1LL << j);

        for (k = i; k < xors.size() && (xors[k] & bit) == 0; k++);
        if (k == xors.size()) {
            j++;
            continue;
        }

        swap(xors[i], xors[k]);
        for (k = i + 1; k < xors.size(); k++)
            if ((xors[k] & bit) == bit)
                xors[k] ^= xors[i];

        done.pb(xors[i]);

        i++; j++;
    }


    for (auto e : done) {
        for (i = 0; i <= lim; i++) {
            ll bit = 1LL << i;

            if (e & bit)
                cnt[i]++;
        }
    }



    for (auto e : now_xors) {
        for (i = 0; i <= lim; i++) {
            ll bit = 1LL << i;

            if (e & bit)
                cnt_way[i]++;
        }
    }
}

ll poww(ll a, ll b) {
    ll ans = 1;

    b = max(b, 0LL);

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}


void solve() {
    ll i;
    ll aux;

    for (i = 0; i <= lim; i++) {
        ll way_one = (cnt_way[i] * (ways - cnt_way[i])) % mod;
        ll way_zero = ((ways * ways - ways) / 2) % mod;
        way_zero = (way_zero + mod - way_one) % mod;


        ll circ_one = poww(2, circles - 1);
        ll circ_zero = circ_one;

        if (cnt[i] == 0) {
            circ_one = 0;
            circ_zero = poww(2, circles);
        }

        aux = (1LL << i) % mod;

        ll how = (way_one * circ_zero) % mod;
        ans = (ans + aux * how) % mod;

        how = (way_zero * circ_one) % mod;
        ans = (ans + aux * how) % mod;

    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
    }

    ans = 0;

    for (i = 1; i <= n; i++) {
        if (us[i]) continue;

        xors.clear();
        done.clear();
        now_xors.clear();
        memset(cnt, 0, sizeof(cnt));
        memset(cnt_way, 0, sizeof(cnt_way));

        dfs(i, 0);
        clean();

        circles = done.size();
        ways = now_xors.size();

        solve();
    }


    printf("%lld", ans);

    return 0;
}