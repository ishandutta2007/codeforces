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

vector <lli> v;
lli M = 1ll << 61;

void mul(lli &a, lli b) {
    if (!b) a = 0;
    else if (a > M / b) a = M;
    else a = a * b;
}

lli modpow(lli a, lli b) {
    lli ans = 1;
    for (; b; b >>= 1, mul(a, a)) {
        if (b & 1) mul(ans, a);
    }
    return ans;
}

lli safe_sqrt(lli x) {
    lli a = sqrt(x);
    // while ((a + 1) * (a + 1) <= x) a++;
    return a;
}

void build() {
    fop (i,3,60) {
        int now = 1;
        lli cur = modpow(now, i);
        while (cur <= (M >> 1)) {
            lli tmp = safe_sqrt(cur);
            if (tmp * tmp != cur) v.pb(cur);
            cur = modpow(++now, i);
        }
        ++i;
    }
}

int f(lli x) {
    return upper_bound(all(v), x) - v.begin() + safe_sqrt(x);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    int t;
    cin >> t;
    while (t--) {
        lli l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << '\n';
    }
}