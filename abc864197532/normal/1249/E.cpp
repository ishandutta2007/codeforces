#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
lli dp[200000][2]; // 0 by stairs / 1 by elevator



int main () {
    int n, k;
    cin >> n >> k;
    int a[n-1], b[n-1];
    fop (i,0,n-1) cin >> a[i];
    fop (i,0,n-1) cin >> b[i];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = a[0];
    dp[1][1] = b[0] + k;
    fop (i,2,n) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i-1];
        dp[i][1] = min(dp[i-1][0] + k, dp[i-1][1]) + b[i-1];
    }
    fop (i,0,n) cout << min(dp[i][0], dp[i][1]) << ' ';
    cout << endl;
}