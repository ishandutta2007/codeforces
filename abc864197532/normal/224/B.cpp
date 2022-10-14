#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
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
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    int n, k, tmp;
    cin >> n >> k;
    map <int, int> m1;
    int a[n];
    fop (i,0,n) cin >> a[i];
    int l = 0, r = 0;
    bool is = false;
    for (; r < n;) {
        while (r < n and m1.size() < k) {
            m1[a[r]]++;
            r++;
        }
        if (r == n and m1.size() < k) break;
        while (l < r and m1.size() == k) {
            m1[a[l]]--;
            if (m1[a[l]] == 0) m1.erase(a[l]);
            l++;
        }
        is = true;
        break;
    }
    if (is) cout << l << ' ' << r << endl;
    else cout << "-1 -1\n";
}