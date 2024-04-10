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
    int n, s;
    cin >> n >> s;
    int sum = 0;
    vector <int> a(n), pref(n + 1);
    forn (i, 0, n) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    int ans = 0, ans_idx = 0;
    forn (i, 0, n) {
        sum += a[i];
        if (--upper_bound(all(pref), s + a[i]) - pref.begin() - 1 > ans) {
            ans_idx = i + 1;
        }
        ans = max(ans, (long long)(--upper_bound(all(pref), s + a[i]) - pref.begin()) - 1);
        if (sum > s) {
            if (i + 1 > ans) {
                ans = i + 1;
                ans_idx = 0;
            }
            break;
        }
    }
    if (sum <= s) {
        cout << "0\n";
        return;
    }
    cout << ans_idx << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}