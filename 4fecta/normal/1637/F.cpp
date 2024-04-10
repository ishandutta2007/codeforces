#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, h[MN], u, v, rt, ans;
vector<int> a[MN];

int dfs(int cur, int par) {
    int mx = 0;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        mx = max(mx, dfs(nxt, cur));
    }
    if (mx < h[cur]) ans += h[cur] - mx, mx = h[cur];
    return mx;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        if (h[i] > h[rt]) rt = i;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> vec;
    for (int nxt : a[rt]) {
        vec.push_back(dfs(nxt, rt));
    }
    sort(vec.begin(), vec.end(), greater<>());
    if (vec.size() == 1) ans += h[rt] + h[rt] - vec[0];
    else ans += h[rt] - vec[0] + h[rt] - vec[1];
    printf("%lld\n", ans);

    return 0;
}