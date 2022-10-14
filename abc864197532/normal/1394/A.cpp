#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d, m, tmp;
    cin >> n >> d >> m;
    vector <int> big, small;
    fop (i,0,n) {
        cin >> tmp;
        if (tmp > m) big.pb(tmp);
        else small.pb(tmp);
    }
    while (small.size() < n) small.pb(0);
    sort(rall(big));
    sort(rall(small));
    vector <lli> pre1 = {0}, pre2 = {0};
    for (int i : big) pre1.pb(pre1.back() + i);
    for (int i : small) pre2.pb(pre2.back() + i);
    lli ans = pre2.back();
    int left = n - 1;
    fop (i,1,big.size() + 1) if (n - 1 - 1ll * (d + 1) * (i - 1) >= 0){
        ans = max(ans, pre2[n - 1 - 1ll * (d + 1) * (i - 1)] + pre1[i]);
    }
    cout << ans << endl;
}