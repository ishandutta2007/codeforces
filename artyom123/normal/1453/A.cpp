#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> a;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (a.find(x) != a.end()) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}