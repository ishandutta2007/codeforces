#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

struct group {
    int l, r;
    ll val;

    bool operator<(const group who) const {
        return l < who.l;
    }
};

int n, m, seed, vmax, i, op, l, r, x, y, cnt;
int a[maxN];
set<group> S;
vector< pair<ll, int> > aux = {};
ll ans;

ll poww(ll a, ll b) {
    ll ans = 1;
    a %= y;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % y;
        b >>= 1;
        a = (a * a) % y;
    }

    return ans;
}

int rnd() {
    int ret = seed;
    seed = (1LL * seed * 7 + 13) % 1000000007;
    return ret;
}

void split() {
    vector<group> aux = {};

    //! left bound
    auto it = S.upper_bound({l, r, 0}); it--;
    if (it->l < l) aux.pb({it->l, l - 1, it->val});
    if (it->r > r) {
        aux.pb({r + 1, it->r, it->val});
        aux.pb({l, r, it->val});
    } else {
        aux.pb({l, it->r, it->val});
    }

    S.erase(it);
    for (auto e : aux) S.insert(e);
    aux.clear();

    //! right bound
    /**/ it = S.upper_bound({r, r, 0}); it--;
    if (it->r > r) aux.pb({r + 1, it->r, it->val});
    if (it->l < l) {
        aux.pb({it->l, l - 1, it->val});
        aux.pb({l, r, it->val});
    } else {
        aux.pb({it->l, r, it->val});
    }

    S.erase(it);
    for (auto e : aux) S.insert(e);
    aux.clear();
}

void op1() {
    while (l <= r) {
        auto it = S.lower_bound({l, r, 0});
        group aux = {it->l, it->r, it->val + x};
        S.erase(it);
        S.insert(aux);
        l = aux.r + 1;
    }
}

void op2() {
    int lini = l;
    while (l <= r) {
        auto it = S.lower_bound({l, r, 0});
        l = it->r + 1;
        S.erase(it);
    }
    S.insert({lini, r, x});
}

void op3() {
    auto it = S.lower_bound({l, r, 0});
    aux.clear();

    while (it->l <= r) {
        aux.pb(mp(it->val, it->r - it->l + 1));
        it++;
    }

    sort(aux.begin(), aux.end());
    for (auto e : aux) {
        if (e.second < x) {
            x -= e.second;
        } else {
            printf("%lld\n", e.first);
            return;
        }
    }
}

void op4() {
    auto it = S.lower_bound({l, r, 0});
    ans = 0;
    while (it->l <= r) {
        ans += (1LL * (it->r - it->l + 1) * poww(it->val, x));
        ans %= y;
        it++;
    }
    printf("%lld\n", ans);
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &seed, &vmax);

    S.insert({n + 1, n + 1, -1});

    for (i = 1; i <= n; i++) {
        a[i] = (rnd() % vmax) + 1;
        S.insert({i, i, a[i]});
    }

    for (i = 1; i <= m; i++) {
        op = (rnd() % 4) + 1;
        l = (rnd() % n) + 1;
        r = (rnd() % n) + 1;

        if (l > r) swap(l, r);

        if (op == 3)
            x = (rnd() % (r - l + 1)) + 1;
        else
            x = (rnd() % vmax) + 1;

        if (op == 4)
            y = (rnd() % vmax) + 1;


        //! write your code below
        if (op >= 3) {
            if (++cnt == 158) {
                cerr << "d";
            }
        }

        split();
        if (op == 1) op1();
        if (op == 2) op2();
        if (op == 3) op3();
        if (op == 4) op4();
    }



    return 0;
}