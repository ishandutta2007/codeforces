#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 309;
pii a[maxn * maxn];
int n, m;
pii p[maxn * maxn];
int used[maxn][maxn];

bool cmp(const pii& x, const pii& y) {
    return x.ss < y.ss;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> a[i].ff;
        a[i].ss = i;
    }
    sort(a, a + n * m);
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            p[a[i * m + e].ss] = mp(i, e);
        }
    }
    sort(a, a + n * m, cmp);
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < m; e++) {
            used[i][e] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        int x = p[i].ff;
        int y = p[i].ss;
        for (int e = 0; e < y; e++) {
            if (used[x][e] != -1 && used[x][e] < a[i].ff) {
                ans++;
            }
        }
        used[x][y] = a[i].ff;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}