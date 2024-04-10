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

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    int ans = 1e9;
    int mx = -1;
    forn (i, 0, n) {
        cin >> a[i];
        if (a[i] <= x)
            mx = max(mx, a[i]);
        else
            ans = min(ans, 2);
    }
    if (mx != -1)
       ans = min(ans, (x + mx - 1) / mx);
   cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}