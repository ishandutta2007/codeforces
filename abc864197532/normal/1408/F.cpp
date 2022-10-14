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

vector <pii> ans;
int n;

void solve(int st, int bit) {
    fop (k,0,bit) {
        vector <bool> vis(n, false);
        fop (i,st,st + (1 << bit)) if (!vis[i] && !vis[i + (1 << k)]) {
                ans.eb(i, i + (1 << k));
                vis[i] = vis[i + (1 << k)] = true;
            }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cur = 0;
    cin >> n;
    vector <int> bit;
    FOP (i,20,0) if (n & (1 << i)) {
        solve(cur, i);
        cur += 1 << i;
        bit.pb(i);
    }
    vector <int> same;
    int j = 0;
    FOP (i,cur,cur - (1 << bit.back())) same.pb(i);
    cur -= 1 << bit.back();
    bit.pop_back();
    while (bit.size() > 1) {
        while (same.size() != (1 << bit.back())) {
            int sz = same.size();
            fop (i,j,j + sz) ans.eb(i, same[i - j]), same.pb(i);
            j += sz;
        }
        FOP (i,cur,cur - (1 << bit.back())) {
            ans.eb(i, same[cur - i - 1]);
            same.pb(i);
        }
        cur -= 1 << bit.back();
        bit.pop_back();
    }
    cout << ans.size() << endl;
    for (auto A : ans) cout << A.X + 1 << ' ' << A.Y + 1 << endl;
}