#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;
const int MOD = 998244353;

int l[N], r[N];
int b[N], a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        a[i] = u;
        mp[u] = i;
    }
    mp[0] = 0;
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 2; i <= m; i++) if (mp[b[i]] < mp[b[i - 1]]) return cout << 0, 0;
    int mn = 2e9;
    int cur = n + 1;
    for (int i = m; i >= 1; i--) {
        while (cur > mp[b[i]]) {
            cur--;
            mn = min(mn, a[cur]);
        }
        if (mn < b[i]) return cout << 0, 0;
    }
    for (int i = 1; i <= m; i++) {
        r[i] = mp[b[i]]; 
        if (r[i] == 0) return cout << 0, 0;
        for (int j = r[i] - 1; j >= 1; j--) {
            if (a[j] < b[i]) {
                l[i] = j + 1;
                break;
            }
        }
    }
    int res = 1;
    for (int i = 1; i <= r[1]; i++) if (a[i] < b[1]) return cout << 0, 0;
    for (int i = 2; i <= m; i++) {
        res = 1LL * res * max(0, r[i] - l[i] + 1) % MOD;
    }
    cout << res;
    return 0;
}