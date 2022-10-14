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
    int n;
    cin >> n;
    vector <lli> a(n), b(n), pre(n + 1, 0);
    fop (i,0,n) cin >> a[i];
    fop (i,0,n) cin >> b[i];
    fop (i,0,n) pre[i + 1] = pre[i] + a[i] + b[i];
    lli ans = 0;
    // odd
    lli cur = 0;
    fop (i,0,n) cur += a[i] * i;
    FOP (i,n,0) cur += b[i] * (2 * n - i - 1);
    ans = cur;
    int now = 0;
    for (int i = 0; i + 2 <= n; i += 2) {
        cur -= a[i] * now;
        cur -= a[i + 1] * (now + 1);
        cur -= b[i] * (2 * n - 1);
        cur -= b[i + 1] * (2 * n - 2);
        cur += a[i] * now;
        cur += a[i + 1] * (now + 3);
        cur += b[i] * (now + 1);
        cur += b[i + 1] * (now + 2);
        cur += (pre[n] - pre[i + 2]) * 2;
        ans = max(ans, cur);
        now += 4;
    }
    now = 2;
    cur = b[0];
    fop (i,1,n) cur += b[i] * (i + 1);
    FOP (i,n,1) cur += a[i] * (2 * n - i);
    ans = max(ans, cur);
    for (int i = 1; i + 2 <= n; i += 2) {
        cur -= b[i] * now;
        cur -= b[i + 1] * (now + 1);
        cur -= a[i] * (2 * n - 1);
        cur -= a[i + 1] * (2 * n - 2);
        cur += b[i] * now;
        cur += a[i] * (now + 1);
        cur += a[i + 1] * (now + 2);
        cur += b[i + 1] * (now + 3);
        cur += (pre[n] - pre[i + 2]) * 2;
        ans = max(ans, cur);
        now += 4;
    }
    cout << ans << endl;
}