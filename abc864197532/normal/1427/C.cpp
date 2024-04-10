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

struct person {
    int t, x, y;
};


int dis (person a, person b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, n;
    cin >> r >> n;
    vector <person> P(n + 1);
    P[0].t = P[0].x = P[0].y = 0;
    fop (i,1,n + 1) cin >> P[i].t >> P[i].x >> P[i].y, P[i].x--, P[i].y--;
    vector <int> dp(n + 1, -1 << 30);
    dp[0] = 0;
    int outside = -1 << 30;
    for (int i = 1, j = 0; i < n + 1; ++i) {
        while (j < i && P[j].t + 2 * r < P[i].t) outside = max(outside, dp[j++]);
        for (int k = j; k < i; ++k) if (P[k].t + dis(P[k], P[i]) <= P[i].t) {
            dp[i] = max(dp[i], dp[k] + 1);
        }
        dp[i] = max(dp[i], outside + 1);
    }
    cout << *max_element(all(dp)) << endl;
}