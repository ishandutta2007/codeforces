#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double
#define ll long long
#define pll pair<long long, long long>

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    sort(all(a));
    sort(all(b));
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (b[i] == a[i] + 1) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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