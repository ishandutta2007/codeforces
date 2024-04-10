#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 50087, logN = 17, K = 222;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    fop (i,0,n) cin >> s[i];
    int l[n][m], r[n][m], u[n][m], d[n][m];
    fop (i,0,n) fop (j,0,m) {
        if (i) {
            if (s[i][j] == '*') u[i][j] = u[i - 1][j] + 1;
            else u[i][j] = 0;
        } else {
            u[i][j] = s[i][j] == '*';
        }
        if (j) {
            if (s[i][j] == '*') l[i][j] = l[i][j - 1] + 1;
            else l[i][j] = 0;
        } else {
            l[i][j] = s[i][j] == '*';
        }
    }

    FOP (i,n,0) FOP (j,m,0) {
        if (i < n - 1) {
            if (s[i][j] == '*') d[i][j] = d[i + 1][j] + 1;
            else d[i][j] = 0;
        } else {
            d[i][j] = s[i][j] == '*';
        }
        if (j < m - 1) {
            if (s[i][j] == '*') r[i][j] = r[i][j + 1] + 1;
            else r[i][j] = 0;
        } else {
            r[i][j] = s[i][j] == '*';
        }
    }
    vector <pair <pii, int>> ans;
    fop (i,0,n) fop (j,0,m) {
        int re = min({u[i][j], d[i][j], l[i][j], r[i][j]});
        if (re <= 1) continue;
        re--;
        ans.pb(mp(mp(i, j), re));
        fop (k,i - re, i + re + 1) {
            s[k][j] = '.';
        }
        fop (k, j - re, j + re + 1) {
            s[i][k] = '.';
        }
    }
    bool is = false;
    fop (i,0,n) fop (j,0,m) is |= s[i][j] == '*';
    if (is) cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        for (auto A : ans) {
            cout << A.X.X + 1 << ' ' << A.X.Y + 1 << ' ' << A.Y << endl;
        }
    }
}