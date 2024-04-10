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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    lli pre[n + 1], suf[n + 1], pw = 1;
    pre[0] = 0;
    fop (i,1,n + 1) pre[i] = (pre[i - 1] * 10 + s[i - 1] - '0') % mod;
    suf[n] = 0;
    FOP (i,n,0) {
        suf[i] = (pw * (s[i] - '0') + suf[i + 1]) % mod;
        pw = pw * 10 % mod;
    }
    lli ans = 0;
    fop (i,0,n + 1) ans = (ans + suf[i] * i) % mod;
    pw = 0;
    FOP (i,n + 1,0) {
        ans = (ans + pre[i] * pw) % mod;
        pw = (pw * 10 + 1) % mod;
    }
    cout << ans << endl;
}