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
const double eps = 1e-6;

vector <int> a;
vector <ld> dp_pre, inv_pre, div_pre, sum_pre;

void calc() {
    int n = a.size();
    inv_pre.assign(n + 1, 0);
    div_pre.assign(n + 1, 0);
    sum_pre.assign(n + 1, 0);
    fop (i,0,n) {
        inv_pre[i + 1] = inv_pre[i] + (1.0 / a[i]);
        sum_pre[i + 1] = sum_pre[i] + a[i];
        div_pre[i + 1] = div_pre[i] + sum_pre[i + 1] / a[i];
    }
}

ld sum(int l, int r) {
    return div_pre[r] - div_pre[l] - sum_pre[l] * (inv_pre[r] - inv_pre[l]);
}

void solve(int l, int r, int x, int y, vector <ld> &dp_cur) {
    if (l >= r) return;
    int mid = l + r >> 1, k = -1;
    fop (i,x,y) {
        if (i >= mid) break;
        ld trans = dp_pre[i] + sum(i + 1, mid + 1);
        if (dp_cur[mid] - trans > eps) {
            k = i;
            dp_cur[mid] = trans;
        }
    }
    assert(k != -1);
    solve(l, mid, x, k + 1, dp_cur);
    solve(mid + 1, r, k, y, dp_cur);
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    a.resize(n);
    fop (i,0,n) cin >> a[i];
    calc();
    dp_pre.resize(n);
    fop (i,0,n) dp_pre[i] = sum(0, i + 1);
    fop (t,1,k) {
        vector <ld> dp_cur(n, 1ll << 60);
        solve(t, n, 0, n + 1, dp_cur);
        swap(dp_pre, dp_cur);
    }
    cout << fixed << setprecision(10) << dp_pre[n - 1] << endl;
}