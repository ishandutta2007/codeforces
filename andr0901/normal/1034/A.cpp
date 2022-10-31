#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
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
    int n;
    cin >> n;
    vector <int> a(n);
    int g = 0;
    forn (i, 0, n) 
        cin >> a[i], g = gcd(g, a[i]);
    forn (i, 0, n) 
        a[i] /= g;
    const int SZ = 2e7 - 5e6 + 5;
    //cout << SZ << "\n";
    vector <int> primes(SZ);
    forn (i, 0, SZ)
        primes[i] = i;
    forn (i, 2, SZ) 
        if (primes[i] == i && i * i <= SZ) 
            for (int j = i * i; j <= SZ; j += i)
                primes[j] = i;
    vector <int> cnt(SZ);
    forn (i, 0, n) {
        while (a[i] > 1) {
            //cout << a[i] << " " << primes[a[i]] << "\n";
            int p = primes[a[i]];
            while (a[i] % p == 0)
                a[i] /= p;
            //cout << a[i] << " " << primes[a[i]] << "\n";
            cnt[p]++;
        }
        //cout << "\n";
    }
    int ans = 1e9;
    forn (i, 2, SZ) 
        ans = min(ans, n - cnt[i]);
    if (ans >=   n)
        cout << -1;
    else 
        cout << ans;
    return 0;
}