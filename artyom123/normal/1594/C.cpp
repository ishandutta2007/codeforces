#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double

const long long INFLL = 1e18;
const int INF = 1e9 + 5;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    vector<int> cnt(n + 1);
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            cnt[i + 1]++;
            t++;
        }
    }
    if (!t) {
        cout << 0 << "\n";
        return;
    }
    for (int x = 1; x <= n; x++) {
        bool ok = 1;
        for (int y = x; y <= n; y += x) {
            if (cnt[y]) ok = 0;
        }
        if (ok) {
            cout << 1 << "\n";
            cout << x << "\n";
            return;
        }
    }
    cout << 2 << "\n";
    cout << n << " ";
    for (int x = 1; x <= n; x++) {
        bool ok = 1;
        for (int y = x; y <= n; y += x) {
            if (cnt[y] && y == n) ok = 0;
        }
        if (ok) {
            cout << x << "\n";
            return;
        }
    }
    return;
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}