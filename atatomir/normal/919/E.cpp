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

#define maxN 1000011

ll a, b, p, x, i, d, pos;
ll an, act, rat, k;
ll sol;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);

    while (b > 0) {
        a %= b;
        swap(a, b);
    }

    return a;
}

ll cmmmc(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }

    return ans;
}

int main()
{
   // freopen("test.in","r",stdin);

    cin >> a >> b >> p >> x;

    an = a;
    for (i = 1; i <= p - 1 && i <= x; i++) {

        act = (an * i) % p;
        rat = p - an;
        rat %= p;

        k = poww(rat, p - 2);
        k = (k * (p + b - act)) % p;
        k *= (p - 1);

        pos = i + k;
        if (pos <= x) {
            sol++;
            sol += (x - pos) / ((p - 1) * p);
        }

        an = (an * a) % p;
    }

    cout << sol;


    return 0;
}