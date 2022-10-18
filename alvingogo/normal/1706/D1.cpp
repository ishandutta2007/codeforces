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
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int ans=487638763;
        for(int i=1;i<=3000;i++){
            int mx=0,mn=487638763;
            int flag=0;
            for(int j=0;j<n;j++){
                int u=min(k,v[j]/i);
                if(u==0){
                    u=1;
                }
                int nw=v[j]/u;
                if(nw>i){
                    u++;
                    if(u>k){
                        flag=1;
                        break;
                    }
                }
                nw=v[j]/u;
                mx=max(mx,nw);
                mn=min(mn,nw);
            }
            if(!flag){
                ans=min(ans,mx-mn);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}