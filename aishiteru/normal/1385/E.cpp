#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt,top,tot,maxn;
int head[1000005],r[1000005],op[1000005],u[1000005],v[1000005];
int q[1000005],s[1000005],h[1000005],st[1000005],Top,dfn[1000005],low[1000005],ti;
struct data{int to,next;}e[1000005];
bool ins[1000005];
void insert(int u,int v)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;}
void topsort()
{
    tot=top=0;
    for(int i=1;i<=n;i++)
        if(!r[i]){s[++top]=i;q[++tot]=i;}
    while(top)
    {
        int x=s[top--];
        for(int i=head[x];i;i=e[i].next)
        {
            r[e[i].to]--;
            if(!r[e[i].to]){s[++top]=e[i].to;q[++tot]=e[i].to;}
        }
    }
}
int Min(int p,int q){return p<q?p:q;}
void scc(int x){
    st[++Top]=x,ins[x]=1,dfn[x]=low[x]=++ti;
    for(int i=head[x],j;i;i=e[i].next)
        !dfn[j=e[i].to]?scc(j),low[x]=Min(low[x],low[j]):low[x]=Min(low[x],ins[j]?dfn[j]:low[x]);
    if(low[x]==dfn[x]){
        int v,len=0;
        do{
            v=st[Top--],++len,ins[v]=0;
        }while(x!=v&&Top);
        maxn=(len>maxn?len:maxn);
    }
}
bool ck(){
    maxn=0;
    for(int i=1;i<=n;++i) if(!dfn[i]) scc(i);
    return maxn>1;
}
int main(){ 
    int T=read();int i;
    while(T--){
        n=read(),m=read();
        for(i=1;i<=n;++i) r[i]=dfn[i]=low[i]=ins[i]=head[i]=0;
        for(i=1;i<=cnt;++i) e[i].to=e[i].next=0;cnt=Top=ti=0;
        for(i=1;i<=m;++i) op[i]=read(),u[i]=read(),v[i]=read();
        for(i=1;i<=m;++i) if(op[i]==1) insert(u[i],v[i]),r[v[i]]++;
        if(ck()){puts("NO");continue;}
        topsort(),puts("YES");
        for(int i=1;i<=n;i++) h[q[i]]=i;
        for(i=1;i<=m;++i){
            if(op[i]==0) h[u[i]]>=h[v[i]]?printf("%d %d\n",v[i],u[i]):printf("%d %d\n",u[i],v[i]);
            if(op[i]==1) printf("%d %d\n",u[i],v[i]);
        }
    }
    return 0;
}