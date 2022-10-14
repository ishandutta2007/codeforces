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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    fop (i,0,n) cin >> s[i];
    bool is = false;
    auto cha = [&](char c) {
        if (c == 'R') return 0;
        if (c == 'B') return 1;
        return 2;
    };
    if (n % 3 == 0) {
        int cnt[3][3];
        fop (i,0,3) fop (j,0,3) cnt[i][j] = 0;
        fop (k,0,3) {
            fop (i,n / 3 * k,n / 3 * (k + 1)) {
                fop (j,0,m) cnt[k][cha(s[i][j])]++;
            }
        }
        int a = 0;
        fop (i,0,3) {
            if (!cnt[i][0] && !cnt[i][1]) a |= 4;
            if (!cnt[i][0] && !cnt[i][2]) a |= 2;
            if (!cnt[i][1] && !cnt[i][2]) a |= 1;
        }
        is |= a == 7;
    }
    if (m % 3 == 0) {
        int cnt[3][3];
        fop (i,0,3) fop (j,0,3) cnt[i][j] = 0;
        fop (k,0,3) {
            fop (i,m / 3 * k,m / 3 * (k + 1)) {
                fop (j,0,n) cnt[k][cha(s[j][i])]++;
            }
        }
        int a = 0;
        fop (i,0,3) {
            if (!cnt[i][0] && !cnt[i][1]) a |= 4;
            if (!cnt[i][0] && !cnt[i][2]) a |= 2;
            if (!cnt[i][1] && !cnt[i][2]) a |= 1;
        }
        is |= a == 7;
    }
    cout << (is ? "YES\n" : "NO\n");
}