#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        s+='$';
        vector<int> dp(n);
        dp[0]=n;
        vector<vector<int> > lcp(n+1,vector<int>(n));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<i;j++){
                lcp[i][j]=lcp[i+1][j+1]+1;
                if(s[i]!=s[j]){
                    lcp[i][j]=0;
                }
            }
        }
        int ans=n;
        for(int i=1;i<n;i++){
            dp[i]=n-i;
            for(int j=0;j<i;j++){
                int u=lcp[i][j];
                if(s[i+u]>s[j+u]){
                    dp[i]=max(dp[i],dp[j]+n-i-lcp[i][j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}