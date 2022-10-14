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
const int mod = 1e9, x = 864197532, N = 200087, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k > n * n) {
        cout << -1 << endl;
        return 0;
    }
    int ans[n][n];
    fop (i,0,n) fop (j,0,n) ans[i][j] = 0;
    fop (i,0,n) fop (j,0,n) if (k >= 2 && ans[i][j] == 0) {
        ans[i][j] = 1;
        ans[j][i] = 1;
        k -= (i != j) + 1;
    }
    fop (i,0,n) if (k && ans[i][i] == 0) ans[i][i] = 1, k--;
    fop (i,0,n) fop (j,0,n) cout << ans[i][j] << " \n"[j == n - 1];
}