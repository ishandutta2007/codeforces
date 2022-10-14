#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087, logN = 18;

int main () {
	ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector <int> able;
        fop (i,0,n) cin >> a[i];
        fop (i,1,n - 1) {
            if (a[i] > a[i - 1] and a[i] > a[i + 1]) able.pb(i);
        }
        int maxx = 0, id = -x;
        fop (i,0,able.size()) {
            int j = upper_bound(able.begin(), able.end(), able[i] + k - 3) - able.begin() - 1;
            if (maxx < j - i + 1) {
                maxx = j - i + 1;
                id = able[j] + 2 - k;
            }
        }
        cout << maxx + 1 << ' ' << max(id + 1, 1) << endl;
    }
}