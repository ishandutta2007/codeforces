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
    string a, b;
    cin >> a >> b;
    vector <vector <int>> pos(26);
    forn (i, 0, sz(a))
        pos[a[i] - 'a'].pb(i);
    int cur = -1;
    int ans = 1;
    forn (i, 0, sz(b)) {
        if (upper_bound(all(pos[b[i] - 'a']), cur) == pos[b[i] - 'a'].end()) {
            if (cur == -1) {
                cout << "-1\n";
                return;
            }
            ans++;
            cur = -1;
            i--;
        } else {
            cur = *upper_bound(all(pos[b[i] - 'a']), cur);
        }
        //cout << cur << " ";
    }
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