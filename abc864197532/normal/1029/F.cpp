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
    lli a, b;
    cin >> a >> b;
    lli sum = a + b, p = 0;
    vector <lli> mn(1 << 24, 1ll << 60);
    for (lli i = 1; i * i <= a; ++i) if (a % i == 0) {
        mn[i] = min(mn[i], a / i);
    }
    for (lli i = 1; i * i <= b; ++i) if (b % i == 0) {
        mn[i] = min(mn[i], b / i);
    }
    for (int i = 2; i < (1 << 24); ++i) {
        mn[i] = min(mn[i], mn[i - 1]);
    }
    for (lli i = 1; i * i <= sum; ++i) if (sum % i == 0) {
        if (mn[i] <= sum / i) p = i;
    }
    cout << (p + sum / p) * 2 << endl;
}