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

const int maxn = 3e5 + 9;
vector<int> g[maxn];
int h[maxn];
int ma[maxn];
int n;

int dfs(int v, int p) {
    int ma1 = 0;
    int ma2 = 0;
    int sum = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        sum += dfs(to, v);
        if (ma[to] > ma2) {
            ma2 = ma[to];
        }
        if (ma2 > ma1) {
            swap(ma1, ma2);
        }
    }
    ma[v] = max(h[v], ma1);
    if (p == -1) {
        if (ma2 >= h[v]) {
            return sum;
        }
        if (ma1 >= h[v]) {
            return sum + (h[v] - ma2);
        }
        return sum + (h[v] - ma1) + (h[v] - ma2);
    } else {
        if (ma1 >= h[v]) {
            return sum;
        }
        return sum + (h[v] - ma1);
    }
}

void solve() {
    cin >> n;
    int e = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (h[i] > h[e]) {
            e = i;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans = dfs(e, -1);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}