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
        vector<int> v(n);
        vector<int> cost(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        for(int i=1;i<n-1;i++){
            cost[i]=max(0ll,1+max(v[i-1],v[i+1])-v[i]);
        }
        if(n%2==1){
            long long ans=0;
            for(int i=1;i<n;i+=2){
                ans+=cost[i];
            }
            cout << ans << "\n";
        }
        else{
            long long cnt=0,ans=1e18;
            for(int i=1;i<n-1;i+=2){
                cnt+=cost[i];
            }
            ans=min(ans,cnt);
            for(int i=n-3;i>=1;i-=2){
                cnt+=cost[i+1]-cost[i];
                ans=min(ans,cnt);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}