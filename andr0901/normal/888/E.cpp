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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    vector <int> b;
    forn (mask, 0, 1 << (n / 2)) {
        int sum = 0;
        forn (i, 0, n / 2) 
            if ((mask >> i) & 1)
                sum = (sum + a[i]) % m;
        b.pb(sum);
    }
    vector <int> c;
    forn (mask, 0, 1 << ((n + 1) / 2)) {
        int sum = 0;
        forn (i, 0, (n + 1) / 2)
            if ((mask >> i) & 1)
                sum = (sum + a[n / 2 + i]) % m;
        c.pb(sum);
    }
    sort(all(b)), sort(all(c));
    // for (int i : b)
    //     cout << i << " ";
    // cout << "\n";
    // for (int i : c)
    //     cout << i << " ";
    // cout << "\n";

    int ans = -1;
    forn (i, 0, sz(b)) {
        auto j = upper_bound(all(c), m - b[i] - 1);
        // cout << b[i] << " ";
        if (j == c.begin()) {
            ans = max(ans, (b[i] + c.back()) % m);
            // cout << c.back();
        } else {
            ans = max(ans, (b[i] + *(--j)) % m);
            // cout << *(--j);
        }
        // cout << "\n";
    }
    cout << ans;
    return 0;
}