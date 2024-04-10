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

const ll maxn=1e6+1,inf=1e18,mod=1e9+7,N=360360;
vector<int>g[maxn];
map<int,int>cnt[maxn];
int n,a[maxn],ans[maxn],mx[maxn];
void Merge(int v,int u){
    if(cnt[v].size()<cnt[u].size()){
        swap(cnt[v],cnt[u]);
        swap(mx[u],mx[v]);
    }
    for(auto x:cnt[u]){
        ll d=x.f,c=x.s;
        cnt[v][d]+=c;
        if( cnt[v][d]>cnt[v][mx[v]] || (cnt[v][d]==cnt[v][mx[v]] && d<mx[v]) )
            mx[v]=d;
    }               
    cnt[u].clear();
}
void dfs(int v,int pr,int depth){
    cnt[v][depth]=1;
    mx[v]=depth;
    for(int i=0;i<g[v].size();i++){
        int to=g[v][i];
        if(to!=pr){
            dfs(to,v,depth+1);
            Merge(v,to);
        }
    }
    //cout<<cnt[v][0]<<" "<<cnt[v][1]<<" "<<cnt[v][2]<<" "<<cnt[v][3]<<" "<<mx[v]<<endl;              
    ans[v]=mx[v]-depth;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
}