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
const int mod = 1e9 + 7, x = 864197532, N = 1000001, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    int k = 100;
    if (n > 2000) k = 50;
    ld ans = 0;
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {return a[i] > a[j];});
    ld aa[k];
    aa[0] = 1;
    fop (i,1,k) aa[i] = aa[i - 1] / 2;
    set <int> s;
    s.insert(-1);
    s.insert(n);
    fop (i,0,n) {
        int v = p[i];
        ld left = 0, right = 0;
        auto it = s.lower_bound(v);
        int t = 0, prev = v;
        for (auto it1 = it; it1 != s.end() && t < k; ++it1, ++t) {
            right += aa[t] * (*it1 - prev);
            prev = *it1;
        }
        t = 0, prev = v;
        for (auto it1 = --it; it1 != s.begin() && t < k; --it1, ++t) {
            left += aa[t] * (prev - *it1);
            prev = *it1;
        }
        if (t < k) {
            left += aa[t] * (prev - *s.begin());
        }
        ans += left * right * a[v];
        s.insert(v);
    }
    cout << fixed << setprecision(10) << ans / n / n / 2 << endl;
}