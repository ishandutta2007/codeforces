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

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

void solve() {
    int c, d;
    cin >> c >> d;
    if (c % 2 != d % 2) {
        cout << -1 << "\n";
        return;
    }
    if (c == 0 && d == 0) {
        cout << 0 << "\n";
        return;
    }
    if (c == d) {
        cout << 1 << "\n";
        return;
    }
    cout << 2 << "\n";
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
    while (t--) {
        solve();
    }
    return 0;
}