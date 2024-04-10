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
const int mod = 998244353, x = 864197532, N = 100087, logN = 17, K = 500;

int StMn[N][logN], StMx[N][logN];

void buildSt() {
    for (int j = 1; j < logN; ++j) {
        for (int i = 1; i + (1 << j) < N; ++i) {
            StMn[i][j] = min(StMn[i][j - 1], StMn[i + (1 << j - 1)][j - 1]);
            StMx[i][j] = max(StMx[i][j - 1], StMx[i + (1 << j - 1)][j - 1]);
        }
    }
}

int queryMn(int l, int r) {
    int g = __lg(r - l);
    return min(StMn[l][g], StMn[r - (1 << g)][g]);
}

int queryMx(int l, int r) {
    int g = __lg(r - l);
    return max(StMx[l][g], StMx[r - (1 << g)][g]);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    vector <int> a(n + 1);
    fop (i,1,n + 1) cin >> a[i], StMn[i][0] = StMx[i][0] = a[i];
    vector <int> dp(n + 1, -1);
    dp[0] = 0;
    buildSt();
    deque <int> dq, mn;
    fop (i,1,n + 1) {
        while (dq.size() && queryMx(dq.front() + 1, i + 1) - queryMn(dq.front() + 1, i + 1) > m) {
            if (dq.front() == mn.front()) mn.pop_front();
            dq.pop_front();
        }
        if (i - l >= 0 && dp[i - l] != -1 && queryMx(i - l + 1, i + 1) - queryMn(i - l + 1, i + 1) <= m) {
            while (mn.size() && dp[mn.back()] >= dp[i - l]) {
                mn.pop_back();
            }
            mn.push_back(i - l);
            dq.push_back(i - l);
        }
        if (dq.size()) dp[i] = dp[mn.front()] + 1;
    }
    cout << dp[n] << endl;
}