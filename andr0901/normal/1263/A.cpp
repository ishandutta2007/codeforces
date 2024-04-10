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
    vector <int> a(3);
    forn (i, 0, 3)
        cin >> a[i];
    sort(all(a));
    int ans = 0;
    ans += min(a[0], a[2] - a[1]);
    a[0] -= ans;
    a[2] -= ans;
    if (a[0] % 2 == 0) {
        a[1] -= a[0] / 2;
        a[2] -= a[0] / 2;
    } else {
        a[1] -= a[0] / 2;
        a[2] -= (a[0] + 1) / 2;
    }
    cout << ans + a[0] + min(a[1], a[2]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}