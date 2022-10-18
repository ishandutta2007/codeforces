#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n,m,k;
    cin >> n >> m >> k;
    vector<set<int> > e(k),f(k);
    vector<vector<int> > v(n);
    vector<int> l(k);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        int nw=-1;
        v[i].resize(a);
        set<int> s;
        for(int j=0;j<a;j++){
            int x;
            cin >> x;
            x--;
            if(nw!=-1){
                e[nw].insert(x);
                f[x].insert(nw);    
            }
            v[i][j]=nw=x;
            s.insert(x);
        }
        if(s.size()!=a){
            for(auto h:v[i]){
                l[h]=1;
            }
        }
    }
    const int mod=998244353;
    auto add=[&](int& x,int y){
        x+=y;
        x-=mod*(x>=mod);
    };
    auto mul=[&](int x,int y){
        return 1ll*x*y%mod;
    };
    vector<int> vis(k);
    function<void(int)> dfs=[&](int r){
        vis[r]=-1;
        for(auto h:e[r]){
            if(!vis[h]){
                dfs(h);
            }
        }
        for(auto h:f[r]){
            if(!vis[h]){
                dfs(h);
            }
        }
    };
    function<int(int)> dfs2=[&](int r){
        vis[r]=1;
        int ans=1;
        for(auto h:e[r]){
            if(!vis[h]){
                ans+=dfs2(h);
            }
        }
        return ans;
    };
    for(int i=0;i<k;i++){
        if(e[i].size()>=2 || f[i].size()>=2 || l[i]){
            dfs(i);
        }
    }
    map<int,int> cnt;
    for(int i=0;i<k;i++){
        if(!vis[i]){
            if(f[i].size()==0){
                cnt[dfs2(i)]++;
            }
        }
    }
    vector<int> dp(m+1,0);
    dp[0]=1;
    for(int i=0;i<m;i++){
        for(auto h:cnt){
            if(i+h.fs<=m){
                add(dp[i+h.fs],mul(h.sc,dp[i]));
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}