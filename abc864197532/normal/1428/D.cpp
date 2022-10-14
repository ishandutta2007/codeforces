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
const int mod = 1e9 + 7, x = 864197532, N = 2501, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <pii> p;
    vector <pii> ans;
    vector <int> more1, tmp, three;
    int rf = 0;
    fop (i,0,n) {
        cin >> a[i];
        if (a[i] == 3) {
            if (three.size()) {
                ans.eb(rf, three.back());
                ans.eb(rf, i);
                rf++;
                three.pop_back();
            }
            three.pb(i);
        } else if (a[i] == 2) {
            tmp.pb(i);
        } else if (a[i] == 1) {
            if (tmp.empty()) {
                more1.pb(i);
            } else {
                p.eb(tmp.back(), i);
                tmp.pop_back();
            }
        }
    }
    if (tmp.size() > 0) {
        cout << -1 << endl;
        return 0;
    }
    if (three.size()) {
        int x = three[0];
        if (more1.size() && x < more1.back()) {
            ans.eb(rf, x);
            ans.eb(rf, more1.back());
            rf++;
            ans.eb(rf, more1.back());
            rf++;
            more1.pop_back();
        } else {
            bool is = false;
            fop (i,0,p.size()) {
                if (x < p[i].X) {
                    ans.eb(rf, x);
                    ans.eb(rf, p[i].X);
                    rf++;
                    is = true;
                    break;
                }
            }
            if (!is) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < p.size(); ++i) {
        int x, y;
        tie(x, y) = p[i];
        ans.eb(rf, x);
        ans.eb(rf, y);
        rf++;
    }
    for (int i : more1) {
        ans.eb(rf, i);
        rf++;
    }
    cout << ans.size() << endl;
    for (auto A : ans) {
        cout << A.X + 1 << ' ' << A.Y + 1 << endl;
    }
}