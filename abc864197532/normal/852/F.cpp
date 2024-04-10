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
const int mod = 998244353, x = 864197532, N = 1000087, logN = 17, K = 500;

lli fac[N], facp[N];

lli modpow(lli a, int b, int mod) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

lli C(int n, int m, int mod) {
    if (n < m) return 0;
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, mod, x = 1;
    cin >> n >> m >> a >> mod;
    lli num = a;
    while (num != 1) {
        x++;
        num = num * a % mod;
    }
    fac[0] = 1;
    fop (i,1,m + 2) fac[i] = fac[i - 1] * i % x;
    fop (i,0,m + 2) facp[i] = modpow(fac[i], x - 2, x);
    lli pre[x + 1];
    pre[0] = 1;
    fop (i,1,x + 1) pre[i] = pre[i - 1] * a % mod;
    vector <lli> ans;
    lli tmp = 1;
    fop (i,0,n) {
        tmp = tmp * pre[C(m, i, x)] % mod;
        ans.pb(tmp);
    }
    reverse(all(ans));
    printv(ans);
}