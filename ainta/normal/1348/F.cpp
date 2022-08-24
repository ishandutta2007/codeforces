#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdlib>
#define pii pair<int,int>
#define SZ 262144
using namespace std;
int n, Res[SZ], vis[SZ*4], cur[SZ*4], par[SZ*4];
vector<int>G[SZ];
vector<int>E[SZ*4];
set<int>A,B;
struct AA{
    int b, e;
}w[SZ];
void Add(int a, int b, int e){
    b+=SZ,e+=SZ;
    while(b<=e){
        if(b&1)E[a].push_back(SZ*2+b);
        if(!(e&1))E[a].push_back(SZ*2+e);
        b=(b+1)>>1,e=(e-1)>>1;
    }
}
void DFS(int a){
    vis[a]=1;
    cur[a]=1;
    for(auto &x : E[a]){
        if(cur[x]){
//            printf("! %d %d\n",a,x);
            int z = a;
            vector<int>T, TT;
            T.push_back(z);
            while(z!=x){
             //   if(z)printf("%d\n",z);
                
                z=par[z];
                T.push_back(z);
            }
            for(auto &t : T)if(t<SZ+SZ)TT.push_back(t);
            reverse(TT.begin(),TT.end());
            int sz = TT.size();
            if(TT[0] > SZ){
                reverse(TT.begin()+1,TT.end());
                reverse(TT.begin(),TT.end());
            }
            puts("NO");
            int i;
            for(i=1;i<=n;i++)printf("%d ",Res[i]);
            puts("");
            
            for(i=0;i<sz;i+=2){
                Res[TT[i]]=TT[i+1]-SZ;
            }
            for(i=1;i<=n;i++)printf("%d ",Res[i]);
            puts("");
            exit(0);
        }
        if(!vis[x]){
            par[x]=a;
            DFS(x);
        }
    }
    cur[a]=0;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].b,&w[i].e);
        G[w[i].b].push_back(i);
    }
    set<pii>Set;
    for(i=1;i<=n;i++){
        for(auto &t : G[i]){
            Set.insert({w[t].e,t});
        }
        pii t = *Set.begin();
        Set.erase(Set.begin());
        Res[t.second] = i;
    }
    for(i=1;i<SZ;i++){
        E[SZ*2+i].push_back(SZ*2+i*2);
        E[SZ*2+i].push_back(SZ*2+i*2+1);
    }
    for(i=1;i<=n;i++){
        E[SZ+Res[i]].push_back(i);
        Add(i, w[i].b, Res[i]-1);
        Add(i, Res[i]+1, w[i].e);
    }
    for(i=1;i<=n;i++)E[SZ*2+SZ+i].push_back(SZ+i);
    DFS(SZ*2+1);
    puts("YES");
    for(i=1;i<=n;i++)printf("%d ",Res[i]);
}