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

lli ask(string &s, string t) {
    lli dp[3] = {0, 0, 0};
    for (char &c : s) {
        if (c == t[2]) {
            dp[2] = (dp[2] + dp[1]) % mod;
        }
        if (c == t[1]) {
            dp[1] = (dp[1] + dp[0]) % mod;
        }
        if (c == t[0]) {
            dp[0] = (dp[0] + 1) % mod;
        }
    }
    return dp[2];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    lli m[n + 1];
    m[0] = 1;
    fop (i,1,n + 1) m[i] = m[i - 1] * 3 % mod;
    lli ans = 0;
    int ques = count(all(s), '?');
    fop (st,0,8) if (ques >= __builtin_popcount(st)) {
        string t = "abc";
        fop (i,0,3) if (st & (1 << i)) t[i] = '?';
        ans = (ans + ask(s, t) * m[ques - __builtin_popcount(st)]) % mod;
    }
    cout << ans << endl;
}