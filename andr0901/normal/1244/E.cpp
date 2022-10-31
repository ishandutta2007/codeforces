#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    map <int, int> cnt;
    int l = 1e9, r = -1e9;
    int n;
    ll k;
    cin >> n >> k;
    forn (i, 0, n) {
        int t;
        cin >> t;
        cnt[t]++;
        l = min(l, t), r = max(r, t);
    }
    while (k && l < r) {
        if (cnt[l] < cnt[r]) {
            int nxt = min(1LL * cnt.upper_bound(l) -> fs, l + k / cnt[l]);
            if (nxt == l)
                break;
            k -= (nxt - l) * cnt[l];
            cnt[nxt] += cnt[l];
            l = nxt;
        } else {
            int nxt = max(1LL * (--cnt.lower_bound(r)) -> fs, r - k / cnt[r]);
            if (nxt == r)
                break;
            k -= (r - nxt) * cnt[r];
            cnt[nxt] += cnt[r];
            r = nxt;
        }
    }
    cout << r - l;
    return 0;
}