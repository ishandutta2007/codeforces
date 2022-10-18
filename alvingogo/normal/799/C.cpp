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
    int n,ca,cb;
    cin >> n >> ca >> cb;
    vector<pair<int,int> > a,b;
    int ans=-1e9,mx=-1e9,my=-1e9;
    for(int i=0;i<n;i++){
        int x,y;
        char c;
        cin >> x >> y >> c;
        if(c=='C'){
            a.push_back({y,x});
            if(y<=ca){
                mx=max(mx,x);
            }
        }
        else{
            b.push_back({y,x});
            if(y<=cb){
                my=max(my,x);
            }
        }
    }
    ans=max(ans,mx+my);
    auto cal=[&](vector<pair<int,int> > f,int g){
        if(f.size()<=1){
            return;
        }
        sort(f.begin(),f.end());
        vector<int> v(f.size());
        v[0]=f[0].sc;
        for(int i=1;i<f.size();i++){
            v[i]=max(v[i-1],f[i].sc);
        }
        int nw=-1;
        for(int i=f.size()-1;i>=0;i--){
            while(nw+1<f.size()){
                if(nw+1<f.size() && f[i].fs+f[nw+1].fs<=g){
                    nw++;
                }
                else{
                    break;
                }
            }
            int u=min(nw,i-1);
            if(u<0){
                continue;
            }
            ans=max(ans,f[i].sc+v[u]);
        }
    };
    cal(a,ca);
    cal(b,cb);
    if(ans<=0){
        cout << 0 << "\n";
    }
    else{
        cout << ans << "\n";
    }
    return 0;
}