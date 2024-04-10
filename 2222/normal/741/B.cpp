#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)      for(int i(a),b_(b);i<b_;++i)
#define REP(i,n)        for(int i=0;i<n;++i)
#define CL(a,x)         memset(a,x,sizeof(a))
#define all(a)          (a).begin(),(a).end()
#define sz(a)           int((a).size())
#define pb              push_back
#define X               first
#define Y               second
using ll =              long long;
using vi =              vector<int>;
using pii =             pair<int, int>;

int n, m, maxW;
int p[1111], w[1111], b[1111], W[1111], B[1111];
vector<pii> g[1111];

int P(int x) { return p[x] == x ? x : p[x] = P(p[x]); }

int main() {
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m >> maxW;
    REP (i, n) {
        p[i] = i;
        cin >> w[i];
    }
    REP (i, n) {
        cin >> b[i];
        g[i].emplace_back();
    }
    REP (i, m) {
        int x, y;
        cin >> x >> y;
        p[P(x - 1)] = P(y - 1);
    }
    REP (i, n) {
        int j = P(i);
        g[j][0].X += w[i];
        g[j][0].Y += b[i];
        g[j].emplace_back(w[i], b[i]);
    }
    REP (i, n) {
        vector<pii> z;
        for (auto& p : g[i])
            if (p.X <= maxW)
                z.pb(p);
        g[i] = z;
    }
    vector<ll> f(maxW * 2 + 2);
    REP (i, n) {
        for (int x = maxW; x >= 0; --x) {
            for (auto p : g[i]) {
                f[x + p.X] = max(f[x + p.X], f[x] + p.Y);
            }
        }
    }
    cout << *max_element(f.begin(), f.begin() + maxW + 1) << endl;
    return 0;
}