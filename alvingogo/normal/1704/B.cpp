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
        int n,x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int maxx=-1,minn=2e9;
        int ans=0;
        for(int i=0;i<n;i++){
            maxx=max(maxx,v[i]);
            minn=min(minn,v[i]);
            if(maxx-minn>2*x){
                ans++;
                maxx=minn=v[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}