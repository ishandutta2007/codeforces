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

int vis[100005], boss[100005], sz[100005], cnt[100005];
pii arr[100005];

int finds(int x) {
    if (x == boss[x])
        return x;
    return boss[x] = finds(boss[x]);
}

void Union(int x, int y) {
    x = finds(x), y = finds(y);
    if (x == y) return;
    sz[y] += sz[x];
    boss[x] = y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, ans = 0;
        cin >> n >> m;
        fill(vis + 1, vis + n + 1, 0);
        fill(cnt + 1, cnt + m + 1, 0);
        iota(boss + 1, boss + m + 1, 1);
        fill(sz + 1, sz + m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            cin >> arr[i].X >> arr[i].Y;
            if (arr[i].X == arr[i].Y)
                continue;
            ++ans;
            if (vis[arr[i].X])
                Union(vis[arr[i].X], i);
            else
                vis[arr[i].X] = i;
            if (vis[arr[i].Y])
                Union(vis[arr[i].Y], i);
            else
                vis[arr[i].Y] = i;
        }
        for (int i = 1; i <= m; ++i) {
            if (vis[arr[i].X] && vis[arr[i].X] != i)
                ++cnt[finds(i)];
            if (vis[arr[i].Y] && vis[arr[i].Y] != i)
                ++cnt[finds(i)];
        }
        for (int i = 1; i <= m; ++i)
            if (finds(i) == i && sz[i] == cnt[i])
                ++ans;
        cout << ans << "\n";
    }
}