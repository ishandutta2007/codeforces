#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

int solve(int a,int b,int h,int w,vector<int> v){
    int x=(a-1)/h+1,y=(b-1)/w+1;
    if(x==1 && y==1){
        return 0;
    }
    int pro=1;
    vector<pair<int,int> > c;
    function<int(int,int)> dfs=[&](int i,int d){
        if(i==c.size()){
            if(d>=x && pro/d>=y){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dfs(i+1,d)){
            return 1;
        }
        for(int j=1;j<=c[i].sc;j++){
            d*=c[i].fs;
            if(dfs(i+1,d)){
                return 1;
            }
            if(d>x){
                break;
            }
        }
        return 0;
    };
    for(int i=0;i<v.size();i++){
        if(c.empty() || v[i]!=c.back().fs){
            c.push_back({v[i],1});
        }
        else{
            c[c.size()-1].sc++;
        }
        pro*=v[i];
        if(dfs(0,1)){
            return i+1;
        }
    }
    return 1e9;
}
signed main(){
    AquA;
    int a,b,h,w,n;
    cin >> a >> b >> h >> w >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    int ans=solve(a,b,h,w,v);
    ans=min(ans,solve(b,a,h,w,v));
    if(ans>1e8){
        cout << -1 << "\n";
    } 
    else{
        cout << ans << "\n";
    }
    return 0;
}