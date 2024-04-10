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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 500, C = 1e5 + 87;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n + 1], u = 1;
    b[0] = 0;
    fop (i,0,n) {
        cin >> a[i];
        b[i + 1] = b[i] + a[i] * u;
        u *= -1;
    }
    int mn = *min_element(b, b + n + 1);
    fop (i,0,n + 1) b[i] -= mn;
    int mx = *max_element(b, b + n + 1);
    int id = 0, now = mx - b[0] - 1;
    set <pii> s1, s2;
    fop (i,0,n) {
        fop (j,0,a[i]) {
            if (i & 1) {
                s2.insert({now++, id++});
            } else {
                s1.insert({now--, id++});
            }
        }
        if (i & 1) now--;
        else now++;
    }
    fop (i,0,mx) {
        fop (k,0,id) {
            if (s1.count({i, k})) cout << '/';
            else if (s2.count({i, k})) cout << '\\';
            else cout << ' ';
        }
        cout << endl;
    }
}