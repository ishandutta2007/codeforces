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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 500, C = 1 << 20;

int bit[N]{};

int solve(vector <int> v, int a, int b) {
    if (v.empty()) return 0;
    int n = v.size();
    if (b - a - 1 < n) {
        cout << -1 << endl;
        exit(0);
    }
    vector <int> lis;
    fop (i,0,n) {
        if (v[i] <= a + i || v[i] >= b - n + i + 1) continue;
        if (lis.empty() || lis.back() <= v[i] - i) lis.pb(v[i] - i);
        else {
            *upper_bound(all(lis), v[i] - i) = v[i] - i;
        }
    }
    return n - lis.size();
}



int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> b(k);
    fop (i,0,n) cin >> a[i];
    if (k == 0) {
        cout << solve(a, -C, 1 << 30) << endl;
        return 0;
    }
    fop (i,0,k) cin >> b[i], b[i]--;
    int ans = 0;
    for (int i = 0; i + 1 < k; ++i) {
        if (a[b[i]] >= a[b[i + 1]]) {
            cout << -1 << endl;
            return 0;
        }
        vector <int> c;
        fop (j,b[i] + 1,b[i + 1]) c.pb(a[j]);
        ans += solve(c, a[b[i]], a[b[i + 1]]);
    }
    vector <int> c;
    fop (i,0,b[0]) c.pb(a[i]);
    ans += solve(c, -C, a[b[0]]);
    c.clear();
    fop (i,b[k - 1] + 1,n) c.pb(a[i]);
    ans += solve(c, a[b[k - 1]], 1 << 30);
    cout << ans << endl;
}