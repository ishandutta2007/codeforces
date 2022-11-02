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

const int maxn = 1e6 + 9;
int a[2][maxn];
bool used[maxn];
int pos[maxn];
int mod = 1e9 + 7;
int n;

void dfs(int i) {
    while (!used[i]) {
        used[i] = 1;
        i = pos[a[0][i]];
    }
}

void solve() {
    cin >> n;
    for (int e = 0; e < 2; e++) {
        for (int i = 0; i < n; i++) {
            cin >> a[e][i];
            a[e][i]--;
        }
    }
    for (int i = 0; i < n; i++) {
        pos[a[1][i]] = i;
        used[i] = 0;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            ans = (ans * 2) % mod;
        }
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