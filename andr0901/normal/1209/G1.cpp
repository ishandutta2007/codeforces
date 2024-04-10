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

struct Node {
    int l = 1e6, r = -1e6, cnt = 0;
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    vector <Node> where(1e6);
    forn (i, 0, n) {
        cin >> a[i];
        where[a[i]].l = min(where[a[i]].l, i);
        where[a[i]].r = max(where[a[i]].r, i);
        where[a[i]].cnt++;
    }
    a.pb(5e5);
    int l = 0, r = -1, cnt_freq = 0, ans = 0;
    forn (i, 0, n + 1) {
        if (i - 1 == r) {
            ans += r - l + 1 - cnt_freq;
            cnt_freq = 0;
            l = i;
        }
        r = max(r, where[a[i]].r);
        cnt_freq = max(cnt_freq, where[a[i]].cnt);
    }
    cout << ans;
    return 0;
}