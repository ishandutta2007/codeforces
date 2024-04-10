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
const int mod = 998244353, x = 864197532, N = 300087, logN = 17, K = 222;

lli frac[N], fracp[N];

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

lli C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return frac[a] * fracp[b] % mod * fracp[a - b] % mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    frac[0] = fracp[0] = 1;
    fop (i,1,N) frac[i] = frac[i - 1] * i % mod;
    fop (i,1,N) fracp[i] = modpow(frac[i], mod - 2);
    int n, m;
    cin >> n >> m;
    vector <int> l(n), r(n), op1(m), op2(m);
    vector <int> cnt(n + 2, 0);
    fop (i,0,n) cin >> l[i] >> r[i], cnt[l[i]]++, cnt[r[i] + 1]--;
    fop (i,0,m) cin >> op1[i] >> op2[i], op1[i]--, op2[i]--;
    lli pre[n + 1][41], now = 0;
    fop (i,0,41) pre[0][i] = 0;
    fop (i,1,n + 1) {
        now += cnt[i];
        fop (j,0,41) {
            pre[i][j] = (pre[i - 1][j] + C(now - j, i - j)) % mod;
        }
    }
    lli ans = 0;
    fop (s,0,1 << m) {
        set <int> se;
        int mxl = 1, mnr = n;
        fop (i,0,m) if (s & (1 << i)) {
            se.insert(op1[i]), se.insert(op2[i]);
        }
        for (int i : se) mnr = min(mnr, r[i]), mxl = max(mxl, l[i]);
        int k = __builtin_popcount(s), l = se.size();
        if (mnr >= mxl) {
            if (k & 1) ans = (ans - (pre[mnr][l] - pre[mxl - 1][l])) % mod;
            else ans = (ans + pre[mnr][l] - pre[mxl - 1][l]) % mod;
        }
    }
    if (ans < 0) ans += mod;
    cout << ans << endl;
}