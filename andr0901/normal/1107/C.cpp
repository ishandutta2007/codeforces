#pragma GCC optimize("Ofast")
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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    a.pb(0);
    vector <char> b(n);
    forn (i, 0, n)
        cin >> b[i];
    b.pb('#');
    int prev = 0;
    ll ans = 0;
    forn (i, 1, n + 1) {
        //cout << prev << " ";
        if (b[i] != b[i - 1]) {
            vector <int> c;
            forn (j, prev, i)
                c.pb(a[j]);
            sort(all(c));
            reverse(all(c));
            forn (j, 0, min(k, (int)c.size()))
                ans += c[j];
            prev = i;
        }
    }
    cout << ans;
    return 0;
}