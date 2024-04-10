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

struct aib {
    int n;
    vector<ll> data;

    void init(int _n) {
        n = _n;
        data = vector<ll>(n + 13, 0);
    }

    int zrs(int x) {
        return (x & (x - 1)) ^ x;
    }

    void add(int x, ll val) {
        while (x <= n) {
            data[x] += val;
            data[x] %= mod;
            x += zrs(x);
        }
    }

    ll sum(int x) {
        ll ans = 0;

        while (x > 0) {
            ans += data[x];
            ans %= mod;
            x -= zrs(x);
        }

        return ans;
    }
};

int n, q, i, x, op;
vector<int> list[maxN];
ll lvl[maxN];

int cnt;
int l[maxN], r[maxN];

aib Plus, Minus;
ll val, k;


void dfs(int node, int root) {
    l[node] = ++cnt;

    for (int to : list[node]) {
        if (to == root) continue;
        lvl[to] = lvl[node] + 1;
        dfs(to, node);
    }

    r[node] = cnt;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        scanf("%d", &x);
        list[x].pb(i);
    }

    dfs(1, 0);
    Plus.init(n);
    Minus.init(n);

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d%lld%lld", &x, &val, &k);
            val += k * lvl[x];
            val %= mod;

            Plus.add(l[x], val);
            Plus.add(r[x] + 1, mod - val);

            Minus.add(l[x], k);
            Minus.add(r[x] + 1, mod - k);
        } else {
            scanf("%d", &x);

            ll ans = Plus.sum(l[x]);
            ans -= (Minus.sum(l[x]) * lvl[x]) % mod;
            ans += mod;
            ans %= mod;

            printf("%lld\n", ans);
        }
    }

    return 0;
}