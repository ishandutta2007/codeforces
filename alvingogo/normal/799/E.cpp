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
    int n,m,k;
    cin >> n >> m >> k;
    if(k>m){
        cout << -1 << "\n";
        return 0;
    }
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].fs;
    }
    int p;
    cin >> p;
    if(p<k){
        cout << -1 << "\n";
        return 0;
    }
    for(int i=0;i<p;i++){
        int a;
        cin >> a;
        a--;
        v[a].sc++;
    }
    cin >> p;
    if(p<k){
        cout << -1 << "\n";
        return 0;
    }
    for(int i=0;i<p;i++){
        int a;
        cin >> a;
        a--;
        v[a].sc+=2;
    }
    int ans=1e18;
    vector<int> c[4];
    for(int i=0;i<n;i++){
        c[v[i].sc].push_back(v[i].fs);
    }
    for(int i=0;i<4;i++){
        sort(c[i].begin(),c[i].end());
    }
    multiset<int> sm,bg;
    int sum=0,zzz=0;
    vector<int> tot(n+4,-1);
    for(auto h:c[0]){
        bg.insert(h);
    }
    for(int i=(int)max(c[1].size(),c[2].size());i>=0;i--){
        sum=m-(k+i);
        if(i<(int)c[1].size()){
            bg.insert(c[1][i]);
        }
        if(i<(int)c[2].size()){
            bg.insert(c[2][i]);
        }
        if(sum<0){
            tot[i]=-1;
            continue;
        }
        if(i<=(int)c[1].size() && i<=(int)c[2].size()){
            while(sm.size()>sum){
                auto h=sm.rbegin();
                zzz-=*h;
                bg.insert(*h);
                sm.erase(sm.find(*h));
            }
            while(sm.size()<sum){
                if(bg.size()){
                    sm.insert(*bg.begin());
                    zzz+=*bg.begin();
                    bg.erase(bg.begin());
                }
                else{
                    tot[i]=-1;
                    break;
                }
            }
            while(bg.size() && sm.size() && *sm.rbegin()>*bg.begin()){
                auto h=*sm.rbegin();
                sm.insert(*bg.begin());
                zzz+=*bg.begin();
                bg.erase(bg.begin());
                sm.erase(sm.find(h));
                zzz-=h;
                bg.insert(h);
            }
            if(sm.size()!=sum){
                tot[i]=-1;
            }
            else{
                tot[i]=zzz;
            }
        }
        else{
            tot[i]=-1;
        }
    }
    vector<int> pre[4];
    for(int i=1;i<=3;i++){
        pre[i].resize(c[i].size()+1);
        pre[i][0]=0;
        for(int j=0;j<c[i].size();j++){
            pre[i][j+1]=pre[i][j]+c[i][j];
        }
    }  
    for(int i=0;i<=c[3].size();i++){
        int z=k-i;
        if(z>(int)c[1].size() || z>(int)c[2].size()){
            continue;
        }
        if(z<0){
            sum=m-i;
            if(sum<0){
                break;
            }
            if(sm.size()<sum){
                continue;
            }
            while(sm.size()>sum){
                auto h=sm.rbegin();
                zzz-=*h;
                bg.insert(*h);
                sm.erase(sm.find(*h));
                
            }
            ans=min(ans,pre[3][i]+zzz);
            continue;
        }
        if(z<tot.size() && tot[z]>=0){
            ans=min(ans,pre[3][i]+pre[1][z]+pre[2][z]+tot[z]);
        }
    }
    if(ans>1e17){
        cout << -1 << '\n';
    }
    else{
        cout << ans << "\n";
    }
    return 0;
}