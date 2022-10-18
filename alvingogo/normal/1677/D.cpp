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
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        int ans=1;
        const int mod=998244353;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i]>i){
                ans=0;
            }
            if(i>=n-k && v[i]!=0 && v[i]!=-1){
                ans=0;
            }
            if(i<k){
                ans=1ll*ans*(i+1)%mod;
            }
            else{
                if(v[i-k]==-1){
                    ans=1ll*ans*(i+1)%mod;
                }
                else if(v[i-k]==0){
                    ans=1ll*ans*(k+1)%mod;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}