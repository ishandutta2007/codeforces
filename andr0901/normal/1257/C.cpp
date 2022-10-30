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

void solve() {
    int n;
    cin >> n;
    int ans = 1e9;
    int j = 0;
    map <int, int> last;
    vector <int> b(n);
    set <int> a;
    forn (i, 0, n) {
        cin >> b[i];
        if (a.find(b[i]) != a.end()) {
            //cout << i << " " << last[b[i]] << "\n";
            ans = min(ans, i - last[b[i]] + 1);
            forn (k, j, last[b[i]] + 1) 
                a.erase(b[k]);
            j = last[b[i]] + 1;
        }
        last[b[i]] = i;
        a.insert(b[i]);
    }
    if (ans == 1e9)
        cout << -1 << "\n";
    else
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