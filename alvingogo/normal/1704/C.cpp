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
        int n,m;
        cin >> n >> m;
        vector<int> v(m);
        for(int i=0;i<m;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        vector<int> d;
        for(int i=0;i<m-1;i++){
            d.push_back(v[i+1]-v[i]-1);
        }
        d.push_back(v[0]+n-v[m-1]-1);
        sort(d.begin(),d.end(),greater<int>());
        int ans=0;
        int tt=1;
        for(int i=0;i<m;i++){
            ans+=max(0ll,d[i]-tt);
            if(d[i]-tt==0){
                ans++;
            }
            tt+=4;
        }
        cout << n-ans << "\n";
    }
    return 0;
}