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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int c = count(all(s), '1');
    vector <int> b;
    int ans = (c == 0);
    set <int> ss;
    for (int k = 1; k <= n; ++k) if (n % k == 0) {
        vector <int> cnt(k, 0);
        for (int j = 0; j < n; j++) {
            cnt[j % k] += (s[j] == '1');
        }
        bool is = true;
        fop (i,0,k) {
            is &= cnt[i] % 2 == 0;
        }
        if (is) ss.insert(k);
    }
    for (int k = 1; k < n; ++k) {
        int g = __gcd(k, n);
        ans += ss.count(g);
    }
    cout << ans << endl;
}