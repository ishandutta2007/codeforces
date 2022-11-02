#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
int L[maxn];
vector<ll> sum[maxn];
vector<int> val[maxn];
void calc(int v) {
    val[v].emplace_back(0);
    if(v * 2 <= n) {
        calc(v * 2);
        if(v * 2 + 1 <= n) {
            calc(v * 2 + 1);
            int i = 0, j = 0;
            vector<int> &a = val[v*2];
            vector<int> &b = val[v*2+1];
            while(i < a.size() || j < b.size()) {
                if(j == b.size() || (i != a.size() && a[i] + L[v * 2] < b[j] + L[v*2 + 1])) {
                    val[v].emplace_back(a[i] + L[v*2]);
                    i++;
                } else {
                    val[v].emplace_back(b[j] + L[v*2 + 1]);
                    j++;
                }
            }
        } else {
            for(int x: val[v*2]) {
                val[v].emplace_back(x + L[v * 2]);
            }
        }
    }
    sum[v].emplace_back(0);
    for(int x: val[v]) {
        sum[v].emplace_back(sum[v].back() + x);
    }
}
ll get(int v, int dep) {
    if(dep <= 0) return 0;
    ll r = lower_bound(val[v].begin(), val[v].end(), dep) - val[v].begin();
    return r * dep - sum[v][r];
}
ll rec(int v, int pa, int dep) {
    if(dep <= 0) return 0;
    if(v == 0) return 0;
    ll ans = rec(v/2, v, dep - L[v]) + dep;
    if(pa!=2*v && v * 2  <= n) {
        ans += get(2*v, dep - L[v * 2]);
    }
    if(pa != 2 * v + 1 && 2 * v + 1 <= n) {
        ans += get(2*v+1, dep - L[v * 2 + 1]);
    }
    return ans;
}
void solve() {
    cin >> n >> m;
    for(int i = 2; i <= n; i++) {
        cin >> L[i];
    }
    calc(1);
    for(int i = 0; i < m; i++) {
        int x, h;
        cin >> x >> h;
        cout << rec(x, -1, h) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}