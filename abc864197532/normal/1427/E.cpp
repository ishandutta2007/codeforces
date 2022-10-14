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

struct op {
    lli a, b;
    char c;
};

vector <op> ans;

void get(lli a, lli b) {// get a * b
    int now = 0;
    vector <lli> no = {a};
    while ((1ll << now) <= b) {
        ans.pb({no[now], no[now], '+'});
        no.pb(no[now] * 2);
        now++;
    }
    lli cur = 0;
    fop (i,0,now) {
        if (b & (1ll << i)) ans.pb({cur, no[i], '+'}), cur += no[i];
    }
    assert(cur == a * b);
}

pll exgcd(lli a, lli b) {
    if (b == 0) return mp(1, 0);
    pll q = exgcd(b, a % b);
    return mp(q.Y, q.X - q.Y * (a / b));
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli n;
    cin >> n;
    ans.pb({n, n, '^'});
    int now = 0;
    lli a = n;
    while ((1 << now + 1) <= n) {
        ans.pb({a, a, '+'});
        now++;
        a *= 2;
    }
    ans.pb({a, n, '^'});
    lli base1 = a ^ n, base2 = n;
    pll p = exgcd(base1, -base2);
    if (base1 * p.X - base2 * p.Y == -1) {
        swap(base1, base2);
        swap(p.X, p.Y);
    }
    if ((p.Y * base2) & 1) {
        p.X += base2;
        p.Y += base1;
    }
    // cout << base1 << ' ' << p.X << endl;
    // cout << base2 << ' ' << p.Y << endl;
    if (p.X < 0) p.X = -p.X;
    if (p.Y < 0) p.Y = -p.Y;
    get(base1, p.X);
    get(base2, p.Y);
    ans.pb({base1 * p.X, base2 * p.Y, '^'});
    cout << ans.size() << endl;
    for (auto A : ans) {
        cout << A.a << ' ' << A.c << ' ' << A.b << endl;
    }
}