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
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 500, C = 1e5 + 87;

int n, k;
string s;
bool vis[2087][1001];
bool dp[2087][1001];
int back[2087][1001];

bool solve(int v, int i) {
    if (vis[v + k][i]) return dp[v + k][i];
    if (s[i] == '?') {
        dp[v + k][i] |= solve(v + 1, i + 1);
        if (dp[v + k + 1][i + 1]) back[v + k][i] = 1;
        dp[v + k][i] |= solve(v - 1, i + 1);
        if (dp[v + k - 1][i + 1]) back[v + k][i] = -1;
        dp[v + k][i] |= solve(v, i + 1);
        if (dp[v + k][i + 1]) back[v + k][i] = 0;
    } else if (s[i] == 'W') {
        dp[v + k][i] = solve(v + 1, i + 1);
        if (dp[v + k][i]) back[v + k][i] = 1;
    } else if (s[i] == 'D') {
        dp[v + k][i] = solve(v, i + 1);
        if (dp[v + k][i]) back[v + k][i] = 0;
    } else {
        dp[v + k][i] = solve(v - 1, i + 1);
        if (dp[v + k][i]) back[v + k][i] = -1;
    }
    vis[v + k][i] = true;
    return dp[v + k][i];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    fop (j,0,n + 1) vis[0][j] = vis[2 * k][j] = true;
    fop (i,0,2087) vis[i][n] = true;
    dp[0][n] = dp[2 * k][n] = true;
    if (solve(0, 0)) {
        int now = k;
        fop (i,0,n) {
            int b = back[now][i];
            now += b;
            if (s[i] == '?') {
                if (b == 1) s[i] = 'W';
                else if (b == 0) s[i] = 'D';
                else s[i] = 'L';
            }
        }
        cout << s << endl;
    }else {
        cout << "NO\n";
    }
}