#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n;
pair<int, int> a[maxn];
int p[maxn];
int u[maxn];
int sz[maxn];
vector<int> g[maxn];
int get(int v) {
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        p[i + 1] = i + 1;
        u[i + 1] = 0;
        sz[i + 1] = 1;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int v = a[i].second;
        for(int to: g[v]) {
            if(u[to]) {
                int x = get(to);
                int y = get(v);
                if(x != y) {
                    ans += sz[x] * 1ll * sz[y] * a[i].first;
                    p[x] = y;
                    sz[y] += sz[x];
                }
            }
        }
        u[v] = 1;
    }
    reverse(a, a + n);
    for(int i = 0; i < n; i++) {
        p[i + 1] = i + 1;
        u[i + 1] = 0;
        sz[i + 1] = 1;
    }
    for(int i = 0; i < n; i++) {
        int v = a[i].second;
        for(int to: g[v]) {
            if(u[to]) {
                int x = get(to);
                int y = get(v);
                if(x != y) {
                    ans -= sz[x] * 1ll * sz[y] * a[i].first;
                    p[x] = y;
                    sz[y] += sz[x];
                }
            }
        }
        u[v] = 1;
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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