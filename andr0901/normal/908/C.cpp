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
    double n, r;
    cin >> n >> r;
    vector <double> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <double> ans(n);
    forn (i, 0, n) {
        ans[i] = r;
        forn (j, 0, i) {
            if (abs(a[i] - a[j]) <= 2 * r)
                ans[i] = max(ans[i], ans[j] + sqrt(4 * r * r - (a[i] - a[j]) * (a[i] - a[j])));
        }
    }
    cout << fixed << setprecision(20);
    forn (i, 0, n)
        cout << ans[i] << " ";
    return 0;
}