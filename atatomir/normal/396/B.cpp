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

const int def = 100000;

ll t, ti, n, i;
bool ciur[def + 11];
vector<ll> primes;

void pre() {
    ll i, j;

    for (i = 2; i <= def; i++) {
        if (ciur[i]) continue;

        primes.pb(i);
        for (j = i * i; j <= def; j += i) ciur[j] = true;
    }
}

bool is_prime(ll x) {
    for (auto e : primes) {
        if (x == e) return true;
        if (x % e == 0) return false;
    }

    return true;
}

ll cmmdc(ll a, ll b) {
    if (a < b) swap(a, b);

    while (b > 0) {
        a %= b;
        swap(a, b);
    }

    return a;
}

void solve(ll n) {
    ll i, l, r;

    if (n == 2) {
        printf("1/6\n");
        return;
    }

    for (l = n; is_prime(l) == false; l--);
    for (r = n + 1; is_prime(r) == false; r++);

    ll a = l * r - 2 * r + 2 * (n - l + 1);
    ll b = 2 * l * r;
    ll d = cmmdc(a, b);

    a /= d;
    b /= d;
    printf("%lld/%lld\n", a, b);
}

int main()
{
    //freopen("test.in","r",stdin);

    pre();

    scanf("%lld", &t);
    for (ti = 1; ti <= t; ti++) {
        scanf("%lld", &n);
        solve(n);
    }


    return 0;
}