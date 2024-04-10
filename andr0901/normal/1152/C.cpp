#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

ll gcd(ll a, ll b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

ll a, b;
ll ansk = 0;

void relax(ll x) {
    ll t = ((a + x - 1) / x) * x;
    ll k = t - a;
    if (t * (t + b - a) / gcd(t, t + b - a) < (a + ansk) * (b + ansk) / gcd(a + ansk, b + ansk))
        ansk = k;
    //cout << x << " " << t << " " << k << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    for (ll i = 1; i * i <= b - a; i++) {
        if ((b - a) % i == 0) 
            relax(i), relax((b - a) / i);
    }
    cout << ansk;
   /* forn (i, 0, 10000) {
        int a = rand() % 1000, b = rand() % 1000;
        if (a > b)
            swap(a, b);
        int ansk = 0;
        forn (k, 0, 10000)
            if ((a + k) * (b + k) / gcd(a + k, b + k) < (a + ansk) * (b + ansk) / gcd(a + ansk, b + ansk))
                ansk = k; 
        if (((a + b - a - 1) / (b - a)) * (b - a) - a != ansk)
            return cout << "WA " << i << " " << a << " " << b << "  " << ansk << "  " << ((a + b - a - 1) / (b - a)) * (b - a) - a, 0;
    }*/
    return 0;
}