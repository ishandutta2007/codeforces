#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=1e5+123,inf=1e18,mod=1e9+7,N=360360;
vector< pair<int,int> > g[maxn];
int n,k,dp[maxn],dpup[maxn];
int len,ans;
map< int , int > mx[maxn];

void dfs1(int v,int p){
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i].f,d=g[v][i].s;
        if(to!=p){
            dfs1(to,v);
            mx[v][to]=dp[to]+d;
            dp[v]=max(dp[v],dp[to]+d);
        }
    }
}

void dfs2(int v,int p){
    set<pair<int,int> >st;
    st.insert(mp(dpup[v],p));
    
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i].f,d=g[v][i].s;
        if(to!=p)
            st.insert(mp(dp[to]+d,to));
    }

    for(int i=0;i<g[v].size();i++){
        int to=g[v][i].f,d=g[v][i].s;
        if(to!=p){
            st.erase(mp(dp[to]+d,to));
            dpup[to]=(*st.rbegin()).f+d;
            st.insert(mp(dp[to]+d,to));
            mx[to][v]=dpup[to];
            dfs2(to,v);
           // cout<<v<<" "<<to<<" "<<mx[v][to]<<" "<<mx[to][v]<<endl;
        }
    }
}
int dfs(int v,int p,int d){
    int cnt=0;
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i].f;
        if(to==p)
            continue;

        if( dfs(to,v,d) || mx[v][to]>d){
            // cout<<v<<" "<<to<<endl;
            len++,cnt++;
        }
    }
    if(cnt>2)
        ans=0;
    if(cnt==2){
        if(v!=p)
            ans=0;
    }
   // cout<<v<<" "<<p<<" "<<ans<<" "<<cnt<<endl;
    return cnt;
}
bool check(int d){
    for(int v=1;v<=n;v++){
        for(int i=0;i<g[v].size();i++){
            int to=g[v][i].f;
            if( mx[v][to]>d && mx[to][v]>d ){ 
                ans=1;
                len=0;
                dfs(v,v,d);
                //cout<<v<<" "<<len<<endl;
                return (ans && len+1<=k);
            }
        }    
    }
    return 1;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int v,u,d;
        cin>>v>>u>>d;    
        g[v].pb(mp(u,d));
        g[u].pb(mp(v,d));
    }
    dfs1(1,1);
    dfs2(1,1);   
    int l=0,r=1e9+123;
    
     
    while(l<=r){
        int m=(l+r)/2;
        if( !check(m) )
            l=m+1;
        else
            r=m-1;
    }
    cout<<l;
}