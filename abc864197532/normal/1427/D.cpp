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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;

vector <vector <int>> ans;
int _n;

void doo(vector <pii> &a) {
    vector <pii> b;
    for (auto A : a) {
        if (b.size() && b.back().X + 1 == A.X) b.back().X++, b.back().Y += A.Y;
        else b.pb(A);
    }
    vector <int> v;
    for (pii A : b) v.pb(A.X);
    sort(all(v));
    for (pii &A : b) A.X = lower_bound(all(v), A.X) - v.begin();
    swap(a, b);
}

void solve(vector <pii> a) {
    int n = a.size();
    if (n == 1) return;
    if (a.back().X != n - 1) {
        vector <pii> b;
        int pre = 0, p = -1;
        fop (i,0,n) {
            if (a[i].X == a.back().X + 1) {
                ans.pb({pre, a[i].Y, _n - pre - a[i].Y});
                p = i;
                break;
            }
            pre += a[i].Y;
        }
        fop (i,p+1,n) b.pb(a[i]);
        b.pb(a[p]);
        fop (i,0,p) b.pb(a[i]);
        doo(b);
        solve(b);
    } else if (a[0].X != 0) {
        vector <pii> b;
        int pre = 0, p = -1;
        fop (i,0,n) {
            if (a[i].X == a[0].X - 1) {
                ans.pb({pre, a[i].Y, _n - pre - a[i].Y});
                p = i;
                break;
            }
            pre += a[i].Y;
        }
        fop (i,p+1,n) b.pb(a[i]);
        b.pb(a[p]);
        fop (i,0,p) b.pb(a[i]);
        doo(b);
        solve(b);
    } else {
        vector <pii> b;
        int pre = 0, p = -1;
        fop (i,1,n - 1) {
            if (a[i].X == a[n - 2].X + 1) {
                ans.pb({a[0].Y, pre, a[i].Y, _n - pre - a[i].Y - a[0].Y - a[n - 1].Y, a[n - 1].Y});
                p = i;
                break;
            }
            pre += a[i].Y;
        }
        b.pb(a.back());
        fop (i,p+1,n - 1) b.pb(a[i]);
        b.pb(a[p]);
        fop (i,1,p) b.pb(a[i]);
        b.pb(a[0]);
        doo(b);
        solve(b);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _n;
    vector <pii> a(_n);
    fop (i,0,_n) cin >> a[i].X, a[i].Y = 1, a[i].X--;
    doo(a);
    solve(a);
    cout << ans.size() << endl;
    for (auto A : ans) {
        vector <int> tmp;
        for (int i : A) if (i) tmp.pb(i);
        cout << tmp.size() << ' ';
        printv(tmp);
    }
}