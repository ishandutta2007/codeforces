#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    int n, r, a, b;
    cin >> n >> r;
    vector <pii> neg, pos;
    fop (i,0,n) {
        cin >> a >> b;
        if (b >= 0) pos.eb(a, b);
        else neg.eb(max(a, -b), b);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), [&](pii i, pii j) {
        return i.X + i.Y > j.X + j.Y;
    });
    int ans1 = 0;
    for (pii A : pos) {
        if (r >= A.X) {
            r += A.Y;
            ans1++;
        }
    }
    int dp[neg.size() + 1][r + 1];
    fop (i,0,neg.size() + 1) {
        fop (j,0,r + 1) {
            dp[i][j] = -1000;
        }
    }
    dp[0][r] = 0;
    fop (i,0,neg.size()) {
        fop (j,0,r + 1) {
            if (j >= neg[i].X and j + neg[i].Y >= 0 and dp[i+1][j + neg[i].Y] < dp[i][j] + 1) dp[i+1][j + neg[i].Y] = dp[i][j] + 1;
            if (dp[i+1][j] < dp[i][j])dp[i+1][j] = dp[i][j];
        }
    }
    int ans2 = 0;
    fop (i,0,r + 1) ans2 = max(ans2, dp[neg.size()][i]);
    cout << ans1 + ans2 << endl;
}