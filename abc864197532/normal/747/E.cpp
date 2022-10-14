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
    string s;
    getline(cin, s);
    vector <pair <string, int>> pp;
    vector <int> v;
    int now = 0, anss = 0;
    vector <string> ans[1 << 20];
    int f = 0;
    pp.pb({});
    for (char c : s) {
        if (c == ',') {
            f ^= 1;
            if (!f) pp.pb({});
        } else {
            if (f) {
                pp.back().Y = pp.back().Y * 10 + c - '0';
            } else {
                pp.back().X += c;
            }
        }
    }
    for (auto p : pp) {
        now = v.size();
        if (v.size()) {
            v.back()--;
        }
        if (p.Y == 0) {
            ans[now].pb(p.X);
        } else {
            ans[now].pb(p.X);
            v.pb(p.Y);
        }
        while (v.size() && v.back() == 0) v.pop_back();
        anss = max(anss, now + 1);
    }
    cout << anss << endl;
    fop (i,0,anss) {
        for (string s : ans[i]) cout << s << ' ';
        cout << endl;
    }
}