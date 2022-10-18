#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> dp(n);
        vector<int> s(n),tag(n);
        for(int i=0;i<n;i++){
            cin >> tag[i];
        }
        for(int j=0;j<n;j++){
            cin >> s[j];
        }
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(tag[i]==tag[j]){
                    continue;
                }
                int a=dp[i],b=dp[j];
                dp[i]=max(dp[i],b+abs(s[i]-s[j]));
                dp[j]=max(dp[j],a+abs(s[i]-s[j]));
            }
        }
        cout << *max_element(dp.begin(),dp.end()) << "\n";
    }
    return 0;
}