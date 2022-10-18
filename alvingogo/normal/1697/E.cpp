#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int inv(int x){
    return x==1?1:mul(inv(mod%x),mod-mod/x);
}
vector<int> fra;
void init(int x){
    fra.resize(x);
    fra[0]=1;
    for(int i=1;i<x;i++){
        fra[i]=mul(fra[i-1],i);
    }
}
int dis(pair<int,int> x,pair<int,int> y){
    return abs(x.fs-y.fs)+abs(x.sc-y.sc);
}
int main(){
    AquA;
    init(105);
    int n;
    cin >> n;
    vector<pair<int,int> > v(n);
    vector<vector<int> > e(n,vector<int>(n)),g(n);
    for(int i=0;i<n;i++){
        cin >> v[i].fs >> v[i].sc;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            e[i][j]=1;
            for(int k=0;k<n;k++){
                if(k==i || k==j){
                    continue;
                }
                if(dis(v[i],v[k])<dis(v[i],v[j])){
                    e[i][j]=0;
                }
            }
        }
    }
    vector<int> vz(n);
    int pt=0,eg=0;
    function<void(int)> dfs=[&](int r){
        vz[r]=1;
        pt++;
        for(int i=0;i<n;i++){
            if(e[r][i]){
                eg++;
                if(vz[i]){
                    continue;
                }
                dfs(i);
            }
        }
    };
    vector<int> ava(n);
    for(int i=0;i<n;i++){
        if(ava[i]){
            continue;
        }
        fill(vz.begin(),vz.end(),0);
        pt=0;
        eg=0;
        dfs(i);
        if(eg!=pt*(pt-1)){
            ava[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(ava[i]){
            for(int j=0;j<n;j++){
                e[i][j]=e[j][i]=0;
            }
        }
    }
    vector<vector<int> > p(101,vector<int>(101));
    for(int i=0;i<=n;i++){
        p[i][0]=1;
        for(int j=1;j<=i;j++){
            p[i][j]=mul(p[i][j-1],i-j+1);
        }
    }
    vector<vector<int> > dp(n+1,vector<int>(n+1));
    dp[0][0]=1;
    int ans=0;
    vector<int> vis(n);
    for(int i=0;i<n;i++){
        if(vis[i]){
            for(int j=0;j<n+1;j++){
                dp[i+1][j]=dp[i][j];
            }
            continue;
        }
        int cnt=1;
        for(int j=0;j<n;j++){
            if(e[i][j]){
                vis[j]=1;
                cnt++;
            }
        }
        for(int j=0;j<n;j++){
            add(dp[i+1][j+1],dp[i][j]);
            if(cnt!=1){
                if(j+cnt<=n){
                    add(dp[i+1][j+cnt],dp[i][j]);
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        add(ans,mul(dp[n][i],p[n][i]));
    }
    cout << ans << "\n";
    return 0;
}