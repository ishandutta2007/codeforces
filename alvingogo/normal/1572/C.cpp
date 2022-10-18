#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
        vector<int> v(n);
        vector<vector<int> > cnt(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            v[i]--;
            cnt[v[i]].push_back(i);
        }
        vector<vector<int> > dp(n+1,vector<int>(n));
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j]=dp[i+1][j];
                for(auto h:cnt[v[i]]){
                    if(i<h && h<=j){
                        dp[i][j]=max(dp[i][j],dp[i+1][h-1]+dp[h][j]+1);
                    }
                }
            }
        }
        cout << n-1-dp[0][n-1] << "\n";
    }
    return 0;
}