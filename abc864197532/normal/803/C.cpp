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
const int mod = 1e9, x = 864197532, N = 200087, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli k, n;
    cin >> k >> n;
    if (n >= 200000 || k < n * (n + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
    vector <lli> fa;
    for (lli i = 1; i * i <= k; ++i) if (k % i == 0) {
        fa.pb(i);
        if (i * i != k) fa.pb(k / i);
    }
    sort(rall(fa));
    for (lli i : fa) {
        if (k / i >= n * (n + 1) / 2) {
            fop (j,1,n) {
                cout << i * j << ' ';
                k -= i * j;
            }
            cout << k << endl;
            return 0;
        }
    }
}