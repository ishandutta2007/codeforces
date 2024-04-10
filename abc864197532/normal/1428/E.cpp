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
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 500;

lli get(pll A) {
    lli n, k;
    tie(n, k) = A;
    if (n < k) return 1ll << 60;
    lli a = n / k;
    return a * a * (k - n % k) + (a + 1) * (a + 1) * (n % k);
}

struct cmp {
    bool operator () (pll a, pll b) {
        pll A = mp(a.X, a.Y + 1);
        pll B = mp(b.X, b.Y + 1);
        return get(a) - get(A) > get(b) - get(B);
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <lli> a(n);
    fop (i,0,n) cin >> a[i];
    /*
    fop (n,1,20) {
        vector <int> v;
        fop (k,1,n + 1) {
            int a = n / k;
            //if (n % k == 0) cout << a * a * k << ' ';
            v.pb(a * a * (k - n % k) + (a + 1) * (a + 1) * (n % k));
        }
        fop (i,1,v.size()) cout << v[0] - v[i] << ' ';
        cout << endl;
    }
     */
    multiset <pll, cmp> s;
    fop (i,0,n) s.insert({a[i], 1});
    k -= n;
    while (k--) {
        pll a = *s.begin(); s.erase(s.begin());
        s.insert(mp(a.X, a.Y + 1));
    }
    lli ans = 0;
    while (s.size()) {
        pll a = *s.begin(); s.erase(s.begin());
        ans += get(a);
    }
    cout << ans << endl;
}