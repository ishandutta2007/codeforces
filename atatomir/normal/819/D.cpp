#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

ll T, n, i, j, aux, rez_d, rez_x, rez_y, limit;
ll a[maxN], jump, ans[maxN];
vector< pair<ll, ll> > ord, pos;
map<ll, bool> M;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }

    ll xx, yy;
    ll d = gcd(b, a % b, xx, yy);
    x = yy;
    y = xx - yy * (a / b);
    return d;
}

void solve(ll l, ll r) {
    ll i, j;
    ll bonus = ord[l].first % rez_d;
    ll d, x, y;

    pos.clear();
    for (i = l; i <= r; i++) {
        ord[i].first -= bonus;
        d = rez_d;
        x = rez_x; x *= ord[i].first / d;
        y = rez_y; y *= ord[i].first / d;

        x = ((x % limit) + limit) % limit;
        pos.pb(mp(x, ord[i].second));
    }

    sort(pos.begin(), pos.end());

    if (pos.size() == 1) {
        ans[pos[0].second] += limit;
        return;
    }

    pos.pb(pos[0]);
    for (i = 1; i < pos.size(); i++) {
        auto p1 = pos[i - 1];
        auto p2 = pos[i];
        ll cnt = (p2.first - p1.first + limit) % limit;
        ans[p1.second] += cnt;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &T, &n);
    for (i = 1; i <= n; i++) scanf("%lld", &a[i]), jump += a[i];
    jump %= T;

    aux = -a[1];
    for (i = 1; i <= n; i++) {
        aux += a[i]; aux %= T;
        if (M[aux]) continue;
        M[aux] = true;
        ord.pb(mp(aux, i));
    }

    rez_d = gcd(jump, T, rez_x, rez_y);
    limit = T / rez_d;

    sort(ord.begin(), ord.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)->bool const {
        return a.first % rez_d < b.first % rez_d;
    });

    for (i = 0; i < ord.size(); i = j) {
        for (j = i; j < ord.size(); j++)
            if (ord[i].first % rez_d != ord[j].first % rez_d)
                break;
        solve(i, j - 1);
    }

    for (i = 1; i <= n; i++) printf("%lld ", ans[i]);


    return 0;
}