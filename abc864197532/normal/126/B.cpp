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
    string s;
    cin >> s;
    int n = s.length();
    int ha[26];
    fop (i,0,26) ha[i] = uniform_int_distribution<int>(1, mod)(rng);
    vector <int> poss;
    vector <lli> pre(n + 1, 0);
    lli now1 = 0, now2 = 0, k = 1;
    fop (i,0,n) {
        now1 = (now1 * x + ha[s[i] - 'a']) % mod;
        now2 = (now2 + ha[s[n - i - 1] - 'a'] * k) % mod;
        k = k * x % mod;
        if (now1 == now2) poss.pb(i);
        pre[i + 1] = now1;
    }
    auto check = [&](int l) {
        l = poss[l] + 1;
        lli aa = pre[l];
        fop (i,1,n - l) {
            if (aa == (pre[i + l] + mod - (pre[i] * modpow(x, l) % mod)) % mod) return true;
        }
        return false;
    };
    int l = 0, r = poss.size();
    while (r - l > 1) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    if (check(l)) cout << s.substr(0, poss[l] + 1) << '\n';
    else cout << "Just a legend\n";
}