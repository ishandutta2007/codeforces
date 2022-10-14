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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 500, C = 1e5 + 87;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <int> lp(C, 1), mu(C, 1);
    lli pow2[C];
    pow2[0] = 1;
    fop (i,1,C) pow2[i] = pow2[i - 1] * 2 % mod;
    for (int i = 2; i < C; ++i) {
        for (int j = i; j < C; j += i) if (lp[j] == 1) {
            lp[j] = i;
        }
    }
    for (int i = 2; i < C; ++i) {
        if (lp[i] == lp[i / lp[i]]) {
            mu[i] = 0;
        } else {
            mu[i] = mu[i / lp[i]] * -1;
        }
    }
    int n, tmp;
    cin >> n;
    vector <int> cnt(C, 0);
    fop (i,0,n) cin >> tmp, cnt[tmp]++;
    lli ans = 0;
    fop (i,1,C) {
        int tmp = 0;
        for (int j = i; j < C; j += i) {
            tmp += cnt[j];
        }
        ans = (ans + (pow2[tmp] - 1) * mu[i]) % mod;
    }
    cout << (ans + mod) % mod << endl;
}