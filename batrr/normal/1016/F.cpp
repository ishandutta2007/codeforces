#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=3e5+123,inf=1e18,mod=1e9+7;
vector< pair<int,int> > g[maxn];
vector<int> path;
int n,m;
ll D,MX,depth[maxn],a[maxn];
bool was[maxn];
bool dfs(int v,int p){                  
    bool res=0;
    if(v==n){
        path.pb(n);
        res=1;
    }
    for(auto x:g[v]){
        if(x.f!=p){
            depth[x.f]=depth[v]+x.s;
            if( dfs(x.f,v) ){
                path.pb(v);
                res=1;
            }
        }
    }
    return res;
}
ll dfs2(int v,int p,int lvl=0){
    was[v]=1;
    ll res=0,cnt=0;
    for(auto x:g[v]){
        int to=x.f,d=x.s;
        if(!was[to]){
            res=max(res,dfs2(to,v,lvl+1)+d);
            cnt++;
        }
    }
    if(cnt>1 || lvl==2){
        while(m--){
            printf("%lld\n",D);
        }    
         exit(0);
       }
    return res;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int v,u,w;
        scanf("%d%d%d",&v,&u,&w);
        g[v].pb({u,w});
        g[u].pb({v,w});
    }
    dfs(1,1);
    D=depth[n];
    reverse(path.begin(),path.end());
    
    for( auto v:path)
        was[v]=1;
    for( auto v:path){           
        a[v]=dfs2(v,v);
    }
    ll cur=-1e18,last=-1e18;
    MX=-1e18;
    for( auto v:path){
        if(v!=1){
            if(a[v]!=0)
                cur=max(cur,last);
            MX=max(MX,cur+a[v]-depth[v]);
        }
        cur=max(cur,last);
        if(a[v]!=0)
            cur=max(cur,a[v]+depth[v]);
        else
            last=a[v]+depth[v];
    }
    //cout<<MX<<endl;
    while(m--){
        int x;
        scanf("%d",&x);
        printf("%lld\n",min(D,D+x+MX));
    }
}