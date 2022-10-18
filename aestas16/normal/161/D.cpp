#include <cstdio>
#include <algorithm>

#define Debug(...) \
    fprintf(stderr,"Line %d, Func %s(): ",__LINE__,__FUNCTION__),\
    fprintf(stderr,__VA_ARGS__);
#define debug(...) fprintf(stderr,__VA_ARGS__);

namespace Template {
    template<class T>void fr(T &a) {
        T s=0,w=1;char ch=getchar();
        while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
        while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
        a=w*s;
    }
    template<class T>T fr() {T a;fr(a);return a;}
    int (*R)()=fr<int>;
    template<class T>T sqr(T a) {return a*a;}
    template<class T>T abs(T a) {return a<0?-a:a;}
    template<class T>T cmin(T a,T b) {return a<b?a:b;}
    template<class T>T cmax(T a,T b) {return a>b?a:b;}
    template<class T>void cswp(T &a,T &b) {T t=a;a=b;b=t;}
}
using namespace Template;

const int N=5e4;
namespace Edges {
    struct Edge {int to,nxt,val;}e[(N<<1)+10];
    int hd[N+10],etot=0;
    void adde(int x,int y,int z) {
        e[++etot]=(Edge){y,hd[x],z},hd[x]=etot;
    }
}
using namespace Edges;
int sz[N+10],dis[N+10],sub[N+10],cnt[N+10];
int a[N+10],Max[N+10],vis[N+10],tot,n,k,rt;
long long ans;

int cmp(int a,int b) {return dis[a]<dis[b];}

void dfs1(int u,int f,int cnt) {
    sz[u]=1,Max[u]=0;
    for(int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if(v==f||vis[v])continue;
        dfs1(v,u,cnt),sz[u]+=sz[v],Max[u]=cmax(Max[u],sz[v]);
    }
    Max[u]=cmax(Max[u],cnt-sz[u]);
    if(rt==0||Max[u]<Max[rt])rt=u;
}
void dfs2(int u,int f,int b) {
    a[++tot]=u,sub[u]=b;
    for(int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if(v==f||vis[v])continue;
        dis[v]=dis[u]+e[i].val,dfs2(v,u,b);
    }
}

void Calc(int u) {
    a[tot=1]=u,dis[u]=0,sub[u]=u;
    for(int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if(vis[v])continue;
        dis[v]=e[i].val,cnt[v]=0,dfs2(v,u,v);
    }
    std::sort(a+1,a+1+tot,cmp);
    for(int i=1;i<=tot;i++) cnt[sub[a[i]]]++;
    int L=1,R=tot;
    while(L<R) {
        if(dis[a[L]]+dis[a[R]]<=k)
            ans+=1+R-L-cnt[sub[a[L]]],cnt[sub[a[L]]]--,L++;
        else cnt[sub[a[R]]]--,R--;
    }
    while(L>1) L--,cnt[sub[a[L]]]++;
    while(R<tot) R++,cnt[sub[a[R]]]++;
    while(L<R) {
        if(dis[a[L]]+dis[a[R]]<k)
            ans-=1+R-L-cnt[sub[a[L]]],cnt[sub[a[L]]]--,L++;
        else cnt[sub[a[R]]]--,R--;
    }
}
void work(int u) {
    vis[u]=1,Calc(u);
    for(int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if(vis[v])continue;
        rt=0,dfs1(v,0,sz[v]),work(rt);
    }
}

int main() {
    n=R(),k=R();
    for(int i=1;i<n;i++) {
        int x=R(),y=R();
        adde(x,y,1),adde(y,x,1);
    }
    dfs1(1,0,n),work(rt);
    return !printf("%I64d\n",ans);
}