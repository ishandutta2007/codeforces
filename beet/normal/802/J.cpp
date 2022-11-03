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

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    SOLVE1::solve();
    return 0;
}