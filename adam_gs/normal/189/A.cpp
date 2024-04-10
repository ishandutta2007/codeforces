#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 1; a <= (b); ++a)
int dp[4007];
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        dp[a]=1; dp[b]=1; dp[c]=1;
        rep(i, n) {
                if(i>a && dp[i-a]!=0) dp[i]=max(dp[i], dp[i-a]+1);
                if(i>b && dp[i-b]!=0) dp[i]=max(dp[i], dp[i-b]+1);
                if(i>c && dp[i-c]!=0) dp[i]=max(dp[i], dp[i-c]+1);
        }
        cout << dp[n];
}