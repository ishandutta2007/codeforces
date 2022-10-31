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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <pii> a(n);
    forn (i, 0, n)
        cin >> a[i].fs >> a[i].sc;
    sort(all(a), [&](pii a, pii b){return a.sc < b.sc;});
    int ans = 0, j = n - 1, s = 0;
    multiset <int> b;
    for (int i = 1e6; i >= 1; i--) {
        while (j >= 0 && a[j].sc >= i) {
            if (b.size() < k) {
                b.insert(a[j].fs);
                s += a[j].fs;
            }
            else if (a[j].fs > *b.begin()) {
                s -= *b.begin();
                b.erase(b.begin());
                b.insert(a[j].fs);
                s += a[j].fs;
            }
            j--;
        }
        ans = max(ans, s * i);
    }
    cout << ans;
    return 0;
}