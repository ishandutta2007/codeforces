#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    vector <pii> ans;
    ans.eb(x, y);
    ans.eb(1, y);
    ans.eb(1, 1);
    vis[x - 1][y - 1] = true;
    vis[0][y - 1] = true;
    vis[0][0] = true;
    fop (i,0,n) {
        if (i & 1) {
            FOP (j,m,0) {
                if (!vis[i][j]) ans.eb(i + 1, j + 1);
            }
        } else {
            fop (j,0,m) {
                if (!vis[i][j]) ans.eb(i + 1, j + 1);
            }
        }
    }
    for (auto A : ans) cout << A.X << ' ' << A.Y << endl;
}