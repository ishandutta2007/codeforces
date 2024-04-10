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

const int maxn = 2e5 + 9;
vector<int> g[maxn];
int n, cnt_p, cnt_l;

int dfs(int v, int pr) {
    int cur = 0;
    for (int to : g[v]) {
        if (to == pr)
            continue;
        cur += dfs(to, v);
    }
    cnt_l += cur;
    if (v == 0) {
        if (cur >= 1) {
            cout << cnt_l - cnt_p << "\n";
        } else {
            cout << cnt_l - cnt_p + 1 << "\n";
        }
        return 0;
    }
    if (cur >= 1) {
        cnt_p++;
        return 0;
    }
    return 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    cnt_p = 0, cnt_l = 0;
    dfs(0, -1);
//    cout << cnt_l - cnt_p << "\n";

    for (int i = 0; i < n; i++) {
        g[i].resize(0);
        g[i].shrink_to_fit();
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}