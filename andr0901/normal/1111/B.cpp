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
#define int long long
#define double long double

typedef long long ll;

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    ll s = 0;
    vector <int> a(n);
    forn (i, 0, n) {
        cin >> a[i];
        s += a[i];
    }
    sort(all(a));
    reverse(all(a));
    while (a.size() > 1 && m > 0) {
        //cout << 1.0 * (s + min(m, (int)a.size() * k)) / a.size() << " " << 1.0 * (s - a.back() + min(m - 1, ((int)a.size() - 1) * k)) / (a.size() - 1) << "\n";
        if (1.0 * (s + min(m, (int)a.size() * k)) / a.size() < 1.0 * (s - a.back() + min(m - 1, ((int)a.size() - 1) * k)) / (a.size() - 1)) {
            s -= a.back();
            a.pop_back();
            m--;
        } else
            break;
    }
    cout << fixed << setprecision(30) << (1.0 * s + min(m, (int)a.size() * k)) / a.size();
    return 0;
}