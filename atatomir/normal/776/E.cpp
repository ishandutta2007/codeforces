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

#define mod 1000000007

const ll def = 1000000;

ll n, k, i, j, x, aux;
bool pr[def + 11];
vector<ll> divs;


//ll f[1024];
/*ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);

    while (b > 0) {
        a %= b;
        swap(a, b);
    }

    return a;
}*/

void pre() {
    ll i, j;

    for (i = 2; i <= def; i++) {
        if (pr[i]) continue;

        divs.pb(i);
        for (j = i * i; j <= def; j += i)
            pr[j] = true;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    /*f[1] = 1;
    for (i = 2; i <= 1000; i++) {
        for (j = 1; j < i; j++)
            if (gcd(j, i - j) == 1)
                f[i]++;

        cerr << i << ' ' << f[i] << '\n';
    }*/


    scanf("%lld%lld", &n, &k);
    k = (k + 1) / 2;

    pre();

    x = n;
    while (x != 1 && k > 0) {
        k--;
        aux = x;


        for (auto e : divs) {
            if (e * e > aux) break;
            if (aux % e) continue;

            x /= e;
            x *= (e - 1);

            while (aux % e == 0) aux /= e;
        }

        if (aux != 1) {
            x /= aux;
            x *= aux - 1;
        }
    }

    printf("%lld", x % mod);


    return 0;
}