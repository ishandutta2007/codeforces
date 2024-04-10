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
    int n,m;
    cin >> n >> m;
    pii area[n];
    fop (i,0,n) {
        cin >> area[i].X >> area[i].Y;
        area[i] = make_pair(min(m, max(1, area[i].X - area[i].Y)), min(m, max(1, area[i].X + area[i].Y)));
    }
    sort(area, area + n);
    int dp[m+1];
    dp[m] = 0;
    FOP (i,m,0) {
        dp[i] = m - i;
        fop (j,0,n) {
            if (area[j].X <= i + 1 and i + 1 <= area[j].Y) {
                dp[i] = dp[i+1];
            }
            if (i < area[j].X) {
                int k = area[j].X - i - 1;
                dp[i] = min(dp[i], k + dp[min(m, k + area[j].Y)]);
            }
        }
    }
    cout << dp[0] << endl;
}