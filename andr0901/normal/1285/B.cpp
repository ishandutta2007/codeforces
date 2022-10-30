#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

void solve() {
    int n;
    cin >> n;
    vector <int> pref(n + 1);
    multiset <int> a = {0};
    int mx = -1e18;
    forn (i, 0, n) {
        int x;
        cin >> x;
        pref[i + 1] = pref[i] + x;
        if (i == n - 1)
            a.erase(a.find(0));
        mx = max(mx, pref[i + 1] - *a.begin());
        //cout << pref[i + 1] - *a.begin() << "\n";
        a.insert(pref[i + 1]);
    }
    if (mx < pref[n])
        cout << "YES\n";
    else
        cout << "NO\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}