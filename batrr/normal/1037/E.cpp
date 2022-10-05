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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
int n,m,k,ans[maxn],cur,a[maxn],b[maxn],sz[maxn];
bool used[maxn],was[maxn];
vector< pair< int,int > > g[maxn];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a[i],&b[i]);
        g[a[i]].pb({b[i],i});
        g[b[i]].pb({a[i],i});
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        sz[i]=g[i].size();
        if( sz[i]<k ){
            used[i]=1;
            q.push(i);
        }
    }
    cur=n;
    while( !q.empty() ){
        int v=q.front();
        q.pop();
        for( auto to:g[v] ){
            if(!was[to.s]){
                sz[to.f]--;
                was[to.s]=1;
                if(sz[to.f]<k && !used[to.f]){
                    q.push(to.f);
                    used[to.f]=1;
                }
            }
        }
        cur--;
    }     
    for(int i=m-1;i>=0;i--){
        while( !q.empty() ){
            int v=q.front();
            q.pop();
            for( auto to:g[v] ){
                if(!was[to.s]){
                    sz[to.f]--;
                    was[to.s]=1;
                    if(sz[to.f]<k && !used[to.f]){
                        q.push(to.f);
                        used[to.f]=1;
                    }
                }
            }
            cur--;
        }     
        ans[i]=cur;
        int v,u;
        v=a[i];
        u=b[i];
        if(!was[i]){
            sz[u]--;
            if( !used[u] && sz[u]<k ){
                q.push(u);
                used[u]=1;
            }
            sz[v]--;
            if( !used[v] && sz[v]<k ){
                q.push(v);
                used[v]=1;
            }
            was[i]=1;
        }
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}