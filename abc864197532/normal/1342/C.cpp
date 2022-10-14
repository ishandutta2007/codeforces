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

void solve() {
    int a, b, q;
    lli l, r;
    cin >> a >> b >> q;
    int all = a * b;
    int aa[all], pre[all];
    fop (i,0,all) {
        if ((i % a) % b != (i % b) % a) aa[i] = 1;
        else aa[i] = 0;
        pre[i] = i ? pre[i - 1] + aa[i] : aa[i];
    }
    auto ask = [&](lli x) {
        lli ans = (x / all) * pre[all - 1];
        x %= all;
        return ans + pre[x];
    };
    while (q--) {
        cin >> l >> r;
        lli ans = ask(r) - ask(l - 1);
        cout << ans << ' ';
    }
    cout << '\n';
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}