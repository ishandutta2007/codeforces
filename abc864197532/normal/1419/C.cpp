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
const int mod = 1e9 + 7, x = 864197532, N = 1000005, logN = 17, K = 90002;

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    int all = accumulate(all(a), 0);
    int cnt = 0;
    fop (i,0,n) {
        if (a[i] ^ x) cnt++;
    }
    if (!cnt) {
        cout << 0 << endl;
        return;
    }
    if (all == x * n) {
        cout << 1 << endl;
        return;
    }
    if (cnt != n) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}