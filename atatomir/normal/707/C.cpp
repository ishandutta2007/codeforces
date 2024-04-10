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

ll x, i;
vector< pair<ll, ll> > divs;

void give_ans(ll a, ll b) {
    printf("%lld %lld", a, b);
    exit(0);
}

void get_divs(ll x) {
    ll cnt;

    for (ll d = 2; d * d <= x; d++) {
        if (x % d != 0) continue;

        cnt = 0;
        while (x % d == 0) {cnt++; x /= d;}
        divs.pb(mp(d, cnt));
    }

    if (x > 1)
        divs.pb(mp(x, 1));
}

void catete() {
    ll m, n, y, z;

    if (x == 1) return;

    m = x * x;
    n = 1;
    if (x % 2 == 0) {
        m /= 2;
        n = 2;
    }

    z = (m + n) / 2;
    y = m - z;

    if (x * x + y * y == z * z && y > 0 && z > 0)
        give_ans(y, z);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &x);
    get_divs(x);
    catete();


    printf("-1");

    return 0;
}