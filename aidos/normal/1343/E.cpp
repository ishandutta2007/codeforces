#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
vector<int> g[maxn];
int p[maxn];
ll sum[maxn];
vector<int> calc(int x) {
    vector<int> dis(n, -1);
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        for(int to: g[v]) {
            if(dis[to] == -1) {
                dis[to] = dis[v] + 1;
                q.push(to);
            }
        }
    }
    return dis;
}
void solve() {
    int a, b, c;
    cin >> n >> m >> a >> b >> c;
    for(int i = 0; i < n; i++) g[i].clear();
    for(int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p, p+m);

    for(int i = 0; i < m; i++) {
        sum[i + 1] = sum[i] + p[i];
        int x, y;
        cin >> x >> y;
        g[x-1].emplace_back(y-1);
        g[y-1].emplace_back(x-1);
    }
    for(int x = m + 1; x <= 3 * m; x++) sum[x] = 1ll<<60;
    vector<int> da = calc(a-1);
    vector<int> db = calc(b-1);
    vector<int> dc = calc(c-1);
    ll ans = 1ll<<60;
    for(int i = 0; i < n; i++) {
        ll cur = sum[db[i]] + sum[db[i] + da[i] + dc[i]];
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}