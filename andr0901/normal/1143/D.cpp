#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    int L = n * k;
    int st = (1 - a + L) % L;
    //cout << st << "\n";
    int ansmin = 1e18, ansmax = -1e18;
    forn (i, 0, n) {
        int fin = (i * k + 1 - b + L) % L;
        int len = (st - fin + L) % L;
        ansmin = min(ansmin, L / gcd(len, L));
        ansmax = max(ansmax, L / gcd(len, L));
        //cout << fin << " " << len << "   ";
        fin = (i * k + 1 + b + L) % L;
        len = (st - fin + L) % L;
        ansmin = min(ansmin, L / gcd(len, L));
        ansmax = max(ansmax, L / gcd(len, L));
        //cout << fin << " " << len << "\n";
    }
    cout << ansmin << " " << ansmax;
    return 0;
}