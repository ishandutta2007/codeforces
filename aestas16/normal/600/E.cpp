#include <cstdio>

#define debug(...)
#ifndef ONLINE_JUDGE
#define debug(...) \
    printf("Debug : Line %d, Function %s():\n",__LINE__,__FUNCTION__),\
    fprintf(stderr,__VA_ARGS__);
#endif
#define ll long long

namespace Templates {
    template<class T>void fr(T &a) {
        T s=0,w=1;char ch=getchar();
        while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
        while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
        a=w*s;
    }
    template<class T>T fr() {T a;fr(a);return a;}
    int (*R)()=fr<int>;
    template<class T>T abs(T a) {return a<0?-a:a;}
    template<class T>T cmax(T a,T b) {return a>b?a:b;}
    template<class T>T cmin(T a,T b) {return a<b?a:b;}
    template<class T>void cswp(T &a,T &b) {T t=a;a=b;b=t;}
}
using namespace Templates;

const int N=1e5;
int cnt[N+10],col[N+10],ch[N+10],sz[N+10],Max,chd;
ll ans[N+10],sum;

namespace Edges {
    struct Edge {int to,nxt;}e[(N<<1)+10];
    int hd[N+10],etot=0;
    void adde(int x,int y) {e[++etot]=(Edge){y,hd[x]},hd[x]=etot;}
}
using namespace Edges;

void update(int u,int f,int val) {
    cnt[col[u]]+=val;
    if(cnt[col[u]]>Max)Max=cnt[col[u]],sum=col[u];
    else if(cnt[col[u]]==Max)sum+=1ll*col[u];
    for(int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if(v==f||v==chd)continue;
        update(v,u,val);
    }
}
void dfs1(int u,int f) {
    sz[u]=1;
    for(int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if(v==f)continue;
        dfs1(v,u),sz[u]+=sz[v];
        if(sz[v]>sz[ch[u]])ch[u]=v;
    }
}
void dfs2(int u,int f,int op) {
    for(int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if(v==f||v==ch[u])continue;
        dfs2(v,u,0);
    }
    if(ch[u])dfs2(ch[u],u,1),chd=ch[u];
    update(u,f,1),ans[u]=sum,chd=0;
    if(op==0)update(u,f,-1),sum=0,Max=0;
}

int main() {
    int n=R();
    for(int i=1;i<=n;i++) fr(col[i]);
    for(int i=1;i<n;i++) {
        int x=R(),y=R();
        adde(x,y),adde(y,x);
    }
    dfs1(1,0),dfs2(1,0,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}