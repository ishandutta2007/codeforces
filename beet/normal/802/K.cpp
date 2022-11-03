#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,K;
vpint G[111111];

namespace SOLVE1{
    int dfs(int v,int p){
        int res=0;
        for(auto &e:G[v]){
            if(e.fi==p)continue;
            chmax(res,dfs(e.fi,v)+e.se);
        }
        return res;
    }
    void solve(){
        cout<<dfs(0,-1)<<endl;
    }
}

int dp[111111];
int dfs(int v,int p){
    vint lis;
    for(auto &e:G[v]){
        if(e.fi==p)continue;
        lis.pb(dfs(e.fi,v)+e.se);
    }

    sort(all(lis));reverse(all(lis));
    for(int i=0;i<K-1&&i<lis.size();i++)dp[v]+=lis[i];
    return dp[v];
}

int dfs2(int v,int p){
    int res=0;
    vint lis;
    for(auto &e:G[v]){
        if(e.fi==p)continue;
        lis.pb(dp[e.fi]+e.se);
    }

    sort(all(lis));reverse(all(lis));
    int sum=0;
    for(int i=0;i<K-1&&i<lis.size();i++)sum+=lis[i];
    for(auto &e:G[v]){
        if(e.fi==p)continue;
        int tmp=dp[e.fi]+e.se;
        int val=sum;
        if(lis.size()<=K-1)val-=tmp;
        else if(lis[K-2]<=tmp)val=val-tmp+lis[K-1];
        chmax(res,val+dfs2(e.fi,v)+e.se);
    }
    return res;
}

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N-1){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    if(K==1){
        SOLVE1::solve();
        return 0;
    }

    dfs(0,-1);
    cout<<dfs2(0,-1)<<endl;
    return 0;
}