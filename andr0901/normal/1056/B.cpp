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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> r(m);
    forn (i, 0, m) {
        if (i <= n % m)
            r[(i * i) % m] += n / m + 1;
        else 
            r[(i * i) % m] += n / m;
        if (!i)
            r[i]--;
    }
    ll ans = 0;
    forn (i, 0, m) 
        forn (j, 0, m) 
            if ((i + j) % m == 0) 
                ans += 1LL * r[i] * r[j];
   /* forn (i, 1, m / 2 + 1) 
        ans += 2LL * r[i] * r[m - i];
    ans += 1LL * r[0] * r[0];*/
    cout << ans;
    return 0;
}