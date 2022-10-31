#include<cstdio>
#include<vector>
#include<algorithm>
#define N 200100
using namespace std;
int f[N],id[N],lv[N],up[N],dwn[N],cnt;
bool wrong;
bool del[N],fr[N];//fb: first reverse tree edge
vector<int> g[N];
vector<int> uq[N],dq[N];
int srch(int x){
    if(f[x]==x) return x;
    return f[x]=srch(f[x]);
}
inline int find(int x){
    return id[srch(x)];
}
void build(int u,int p){
    up[u]=dwn[u]=id[u]=lv[u]=++cnt;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==p&&!fr[u]){
            fr[u]=true;
            continue;
        }
        if(id[g[u][i]]){
            lv[u]=min(lv[u],id[g[u][i]]);
        }
        else{
            build(g[u][i],u);
            lv[u]=min(lv[u],lv[g[u][i]]);
        }
    }
    for(int i=0;i<uq[u].size();i++){
        if(id[uq[u][i]]){
            if(del[uq[u][i]]){
                wrong=true;
                continue;
            }
            up[u]=min(up[u],find(uq[u][i]));
            dwn[uq[u][i]]=min(dwn[uq[u][i]],find(uq[u][i]));
        }
    }
    for(int i=0;i<dq[u].size();i++){
        if(id[dq[u][i]]){
            if(del[dq[u][i]]){
                wrong=true;
                continue;
            }
            dwn[u]=min(dwn[u],find(dq[u][i]));
            up[dq[u][i]]=min(up[dq[u][i]],find(dq[u][i]));
        }
    }
    f[u]=p;
}
void check(int u){
    del[u]=true;
    for(int i=0;i<g[u].size();i++){
        if(del[g[u][i]]) continue;
        check(g[u][i]);
        dwn[u]=min(dwn[u],dwn[g[u][i]]);
        up[u]=min(up[u],up[g[u][i]]);
    }
    if(lv[u]==id[u]){
        if(up[u]<id[u]&&dwn[u]<id[u]) wrong=true;
    }
}
int main(){
    int n,m,q,x,y;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) f[i]=i;
    while(m--){
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    while(q--){
        scanf("%d%d",&x,&y);
        uq[x].push_back(y);
        dq[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!id[i]){
            build(i,0);
            check(i);
        }
    }
    if(wrong) puts("No");
    else puts("Yes");
    return 0;
}