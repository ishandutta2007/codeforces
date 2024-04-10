#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int dp[1000000][2];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int n;
    cin >> n;
    int r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    int d;
    cin >> d;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0][0] = a[0]*r1+r3;
    dp[0][1] = d*2+min(a[0]*r1+r1*2, r2+r1);
    for(int i = 1; i < n; ++i){
        dp[i][0] = dp[i-1][0]+d+a[i]*r1+r3;
        int k = 0;
        if(i+1 < n)
            k = d;
        dp[i][0] = min(dp[i][0], dp[i-1][1]+k+a[i]*r1+r3);
        dp[i][0] = min(dp[i][0], dp[i-1][1]+min(a[i]*r1+r1*2, r2+r1)+d);
        dp[i][1] = min(dp[i-1][0], dp[i-1][1])+d+d*2+min(a[i]*r1+r1*2, r2+r1);
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
    return 0;
}