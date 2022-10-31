#pragma GCC optmize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int MOD = 998244353;
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> b;
    forn (i, 0, n) {
        cin >> a[i];
        b[a[i]] = i;
    }
    ll ans = 1;
    int j = 0;
    for (int i = 0; i < n; i++) {
        //j = max(j, b[a[i]]);
        //cout << b[a[i]] << " " << j << "\n";
        if (j < i)
            ans = (2 * ans) % MOD;
        j = max(j, b[a[i]]);
    }
    cout << ans;
    return 0;
}