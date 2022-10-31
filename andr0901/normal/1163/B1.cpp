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
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    multiset <pii> a;
    vector <int> b(1e5 + 1);
    int ans = -1;
    forn (i, 0, n) {
        int t;
        cin >> t;
        if (b[t])
            a.erase({b[t], t});
        b[t]++;
        a.insert({b[t], t});
        pii t1 = *a.begin();
        a.erase(a.begin());
        if (t1.fs - 1 != 0)
            a.insert({t1.fs - 1, t1.sc});
        if (a.empty() || (*a.begin()).fs == (*--a.end()).fs)
            ans = max(ans, i);
        if (t1.fs - 1 != 0)
            a.erase(a.find({t1.fs - 1, t1.sc}));
        a.insert(t1);
        pii t2 = *(--a.end());
        a.erase(--a.end());
        a.insert({t2.fs - 1, t2.sc});
        if ((*a.begin()).fs == (*--a.end()).fs)
            ans = max(ans, i);
        a.erase(a.find({t2.fs - 1, t2.sc}));
        a.insert(t2);
    }
    cout << ans + 1;
    return 0;
}