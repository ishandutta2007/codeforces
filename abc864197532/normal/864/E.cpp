#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, x = 864197532, N = 100001, logN = 17;

int dp[2001][101];
pii pre[2001][101];

struct item {
    int t, d, v, id;
    bool operator < (const item o) {
        return d < o.d;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <item> a(n);
    fop (i,0,n) cin >> a[i].t >> a[i].d >> a[i].v, a[i].id = i + 1;
    sort(all(a));
    fop (i,0,n) {
        fop (j,0,2001) {
            dp[j][i + 1] = dp[j][i];
            pre[j][i + 1] = mp(j, i);
        }
        for (int j = a[i].d - 1; j >= a[i].t; --j) {
            dp[j][i + 1] = max(dp[j - a[i].t][i] + a[i].v, dp[j][i + 1]);
            if (dp[j][i + 1] == dp[j - a[i].t][i] + a[i].v) {
                pre[j][i + 1] = mp(j - a[i].t, i);
            }
        }
        fop (j,1,2001) {
            dp[j][i + 1] = max(dp[j][i + 1], dp[j - 1][i + 1]);
            if (dp[j][i + 1] == dp[j - 1][i + 1]) pre[j][i + 1] = mp(j - 1, i + 1);
        }
    }
    cout << dp[2000][n] << endl;
    int i = 2000, j = n;
    vector <int> ans;
    while (j) {
        int ii, jj;
        tie(ii, jj) = pre[i][j];
        if (dp[ii][jj] != dp[i][j]) {
            ans.pb(a[j - 1].id);
        }
        i = ii, j = jj;
    }
    cout << ans.size() << endl;
    reverse(all(ans));
    printv(ans);
}