#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1 << 30, logN = 17, K = 90002;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s[4][n];
    int cost[4][2];
    fop (i,0,4) cost[i][0] = cost[i][1] = 0;
    fop (k,0,4) {
        fop (i,0,n) cin >> s[k][i];
        fop (i,0,n) fop (j,0,n) {
            if (s[k][i][j] == '0' + ((i + j) & 1)) cost[k][0]++;
            else cost[k][1]++;
        }
    }
    int ans = 1 << 30;
    fop (st,0,1 << 4) if (__builtin_popcount(st) == 2) {
        int tmp = 0;
        fop (i,0,4) {
            if (st & (1 << i)) {
                tmp += cost[i][0];
            } else {
                tmp += cost[i][1];
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}