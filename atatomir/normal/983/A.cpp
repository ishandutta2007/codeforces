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

ll n, i, p, q, b;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    ll d = gcd(p, q);
    p /= d;
    q /= d;

    for (int tms = 1; tms <= 65; tms++) {
        if (q == 1) break;
        d = gcd(b, q);
        if (d == 1) break;
        while (q % d == 0) q /= d;
    }

    if (q != 1)
        printf("Infinite\n");
    else
        printf("Finite\n");
}

int main()
{
    //freopen("test.in","r",stdin);


    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &p, &q, &b);
        solve();
    }


    return 0;
}