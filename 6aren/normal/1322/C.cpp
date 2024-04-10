#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 500005;

vector<int> g[N];
long long c[N];

const int P1 = 1000000007;
const int P2 = 1000000009;
const int BASE = 1000001;

ii operator + (ii x, ii y) {
    return {(x.x + y.x) % P1, (x.y + y.y) % P2};
}

ii operator - (ii x, ii y) {
    return {(x.x - y.x + P1) % P1, (x.y - y.y + P2) % P2};
}

ii operator * (ii x, int y) {
    return {(1LL * x.x * y) % P1, (1LL * x.y * y) % P2};
}

ii operator * (ii x, ii y) {
    return {(x.x * 1LL *  y.x) % P1, (x.y * 1LL * y.y) % P2};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[v].pb(u);
        }
        map<ii, long long> mp;
        for (int i = 1; i <= n; i++) {
            if (g[i].size() == 0) continue;
            sort(all(g[i]));
            ii has = {0, 0};
            for (int e : g[i]) {
                has = has * BASE + make_pair(e, e);
            }
            mp[has] += c[i];
        }
        long long GCD = 0;
        for (auto u : mp) {
            GCD = __gcd(GCD, u.y);
        }
        cout << GCD << '\n'; 
    }
    return 0;
}