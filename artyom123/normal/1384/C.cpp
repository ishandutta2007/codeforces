#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const ll INF = 2e18 + 1;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << -1 << "\n";
            return;
        }
    }
    int ans = 0;
    for (char c = 'a'; c <= 't'; c++) {
        char mn = 'z';
        vector<int> kek;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && a[i] == c) {
                mn = min(mn, b[i]);
                kek.pb(i);
            }
        }
        if (mn == 'z') continue;
        for (auto &lol : kek) a[lol] = mn;
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}