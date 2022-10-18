#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const ll INF = 1e18;

vector<int> G[200005];
int arr[200005], root;
ll ans[200005];

pll dfs(int u, int f) {
    int mx = 0, sx = 0;
    ll sum = 0;
    if (SZ(G[u]) == 1 && u != root) {
        ans[u] = INF;
        return pll(arr[u], arr[u]);
    }
    for (int v : G[u])
        if (v != f) {
            pll rt = dfs(v, u);
            if (rt.X > mx) {
                sx = mx;
                mx = rt.X;
                ans[u] = ans[v];
            }
            else if (rt.X > sx) {
                sx = rt.X;
            }
            if (rt.X == mx)
                ans[u] = min(ans[u], ans[v]);
            sum += rt.Y;
        }
    if (arr[u] > mx) {
        sum += arr[u] - mx;
        mx = arr[u];
    }
    if (arr[u] > sx)
        ans[u] = min((ll)mx - sx, ans[u] + arr[u] - sx);
    else
        ans[u] = min((ll)mx - sx, ans[u]);
    return pll(mx, sum);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    root = max_element(arr + 1, arr + n + 1) - arr;
    pll rt = dfs(root, root);
    cout << rt.Y + ans[root] << "\n";
}