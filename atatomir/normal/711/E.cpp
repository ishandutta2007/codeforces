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

#define mod 1000003

ll n, k, i;
ll inv;

ll up, down;
ll simp;


ll poww(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

ll how_many(ll x) {
    if (x <= 1) return 0;
    return (x / 2) + how_many(x / 2);
}

void comp_up() {
    ll i;
    ll bg;
    ll prod;

    simp = how_many(k - 1);
    if (k >= 2 * mod) {
        up = 0;
        return;
    }

    up = 1;
    bg = poww(2, n);

    for (i = 1; i <= k; i++) {
        if (i != 1) up = (up * bg) % mod;
        bg = (mod + bg - 1) % mod;
    }


    up *= poww(inv, simp);
    up %= mod;
}



void comp_down() {
    down = poww(2, n);
    down = poww(down, k - 1);
    down = (down * poww(inv, simp)) % mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    inv = poww(2, mod - 2);
    scanf("%lld%lld", &n, &k);

    if (k == 1) {
        printf("0 1");
        return 0;
    }

    if (n <= 60) {
        if ((1LL << n) < k) {
            printf("1 1");
            return 0;
        }
    }

    comp_up();
    comp_down();

    up = (mod + down - up) % mod;

    printf("%lld %lld", up, down);


    return 0;
}