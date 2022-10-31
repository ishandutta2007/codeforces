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
#define int long long

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    int g = 0;
    forn (i, 0, n - 1)
        g = gcd(g, (a[i + 1] - a[i]));
    //cout << g;
    forn (i, 0, m) {
        int t;
        cin >> t;
        if (g % t == 0) {
            return cout << "YES\n" << a[0] << " " << i + 1, 0;
        }
    }
    cout << "NO";
    return 0;
}