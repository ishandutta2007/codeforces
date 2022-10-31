#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define ordered_set tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update>

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> a(m);
    forn (i, 0, n) {
        int t;
        cin >> t, t--;
        a[t]++;
    }
    vector <pii> b(q);
    forn (i, 0, q)
        cin >> b[i].fs, b[i].sc = i;
    sort(all(b));
    vector <pii> c(m);
    forn (i, 0, m)
        c[i] = {a[i], i};
    sort(all(c));
    vector <int> ans(q);
    int timer = n + 1, i = 0, j = 0, prev = c[0].fs;
    ordered_set d;
    while (i < m) {
        //cout << i << " " << j << " " << prev << " " << timer << "\n";
        int cur = c[i].fs;
        int diff = cur - prev;
        while (j < q && b[j].fs < timer + diff * sz(d)) {
            if (timer <= b[j].fs)
                ans[b[j].sc] = *d.find_by_order((b[j].fs - timer) % sz(d));
            j++;
        }
        timer = timer + diff * sz(d);
        while (i < m && c[i].fs == cur) {
            d.insert(c[i].sc);
            i++;
        }
        prev = cur;
    }
    //cout << j;
    while (j < q) {
        if (timer <= b[j].fs)
            ans[b[j].sc] = *d.find_by_order((b[j].fs - timer) % sz(d));
        j++;
    }
    forn (i, 0, q)
        cout << ans[i] + 1 << "\n";
    return 0;
}