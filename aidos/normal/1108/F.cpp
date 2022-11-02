#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, m;
int p[maxn];
struct edge{
    int u, v, w;
    bool friend operator < (edge a, edge b) {
        return a.w < b.w;
    }
    void read() {
        cin >> u >> v >> w;
    }
};
edge e[maxn];

int used[maxn];
int get(int v) {
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        e[i].read();
    }
    sort(e, e + m);
    for(int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int ans = -(n-1);
    for(int i = 0; i < m; i++) {
        if(i > 0 && e[i].w == e[i-1].w) continue;
        for(int j = i; j < m; j++) {
            if(e[i].w == e[j].w) {
                int u = e[j].u;
                int v = e[j].v;
                int pu = get(u);
                int pv = get(v);
                if(pu != pv) {
                    ans++;
                }
            } else {
                break;
            }
        }
        for(int j = i; j < m; j++) {
            if(e[i].w == e[j].w) {
                int u = e[j].u;
                int v = e[j].v;
                int pu = get(u);
                int pv = get(v);
                if(pu != pv) {
                    p[pu] = pv;
                }
            } else {
                break;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}