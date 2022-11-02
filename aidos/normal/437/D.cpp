#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
vector<int> g[maxn];
pii a[maxn];
int p[maxn];
int u[maxn];
int sz[maxn];
int get(int v) {
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
        p[i + 1] = i + 1;
        sz[i + 1] = 1;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    sort(a, a + n);
    long double ans = 0;
    for(int i = n-1; i >= 0; i--) {
        int v = a[i].second;
        u[v] = 1;
        for(int to: g[v]) {
            if(u[to]) {
                int x = get(to);
                int y = get(v);
                if(x != y) {
                    p[x] = y;
                    ans += a[i].first * 1ll * sz[x] * sz[y];
                    sz[y] += sz[x];
                }
            }
        }
    }
    ans *= 2;
    ans /= n;
    ans /= n-1;
    printf("%.12lf\n", (double) ans);
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}