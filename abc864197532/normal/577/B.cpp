#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 1000001, logN = 17;

int main () {
    int n, m, tmp;
    cin >> n >> m;
    vector <int> a(n);
    if (n > m) {
        cout << "YES\n";
        return 0;
    }
    fop (i,0,n) {
        cin >> a[i];
        a[i] %= m;
    }
    vector <bool> dp(m, false);
    fop (i,0,n) {
        vector <int> add;
        add.pb(a[i]);
        fop (j,0,m) if (dp[j]) {
            add.pb((j + a[i]) % m);
        }
        for (int j : add) dp[j] = true;
    }
    cout << (dp[0] ? "YES\n" : "NO\n");
}