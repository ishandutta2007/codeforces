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

int main() {
    int n;
    cin >> n;
    vi ans(n, -1u/2);
    for (int t = 0; (1 << t) < n; ++t) {
        vi q[2];
        REP (i, n) q[(i >> t) & 1].pb(i);
        REP (l, 2) {
            cout << q[l].size() << endl;
            for (int x : q[l]) {
                cout << x + 1 << ' ';
            }
            cout << endl;
            vi r(n);
            REP (i, n) cin >> r[i];
            for (int i : q[l ^ 1]) {
                ans[i] = min(ans[i], r[i]);
            }
        }
    }
    cout << -1 << endl;
    REP (i, n) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}