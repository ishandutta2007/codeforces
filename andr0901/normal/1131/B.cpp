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
    int n;
    cin >> n;
    vector <pii> a(n + 1);
    forn (i, 1, n + 1)
        cin >> a[i].fs >> a[i].sc;
    ll ans = 0;
    forn (i, 1, n + 1) {
        ans += max(0, min(a[i].fs, a[i].sc) - max(a[i - 1].fs, a[i - 1].sc) + 1);
        if (a[i].fs == a[i].sc)
            a[i].fs++, a[i].sc++;
    }
    cout << ans;
    return 0;
}