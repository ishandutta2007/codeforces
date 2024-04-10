#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second

void solve() {
    int n;
    cin >> n;
    int p[n], c[n];
    pii pp[n];
    bool vis[n];
    vector <vector <int>> color;
    fop (i,0,n) cin >> p[i], p[i]--;
    fop (i,0,n) cin >> c[i];
    fop (i,0,n) vis[i] = false;
    int ans = n;
    fop (i,0,n) {
        if (!vis[i]) {
            int pos = i;
            color.pb({});
            do {
                vis[pos] = true;
                color.back().pb(pos);
                pos = p[pos];
            } while (!vis[pos]);
        }
    }
    fop (i,0,color.size()) {
        vector <int> f;
        for (int j = 1; j * j <= color[i].size(); ++j) {
            if (color[i].size() % j == 0) {
                f.pb(j);
                f.pb(color[i].size() / j);
            }
        }
        for (int p : f) {
            fop (k,0,p) {
                int now = -1;
                bool is = true;
                for (int j = k; j < color[i].size(); j += p) {
                    if (~now) {
                        is &= now == c[color[i][j]];
                    } else {
                        now = c[color[i][j]];
                    }
                }
                if (is) ans = min(ans, p);
            }
        }
    }
    cout << ans << '\n';
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}