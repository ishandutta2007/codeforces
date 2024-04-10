#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#define LL long long
#define For(i,a,b) for(int i=(int)(a),i_E=(int)(b);i<=i_E;i++)
#define DFor(i,a,b) for(int i=(int)(a),i_E=(int)(b);i>=i_E;i--)
#define cross(i,a) for(int i=hd[(a)];i;i=pr[i])
using namespace std;
inline LL Max(LL a,LL b){return a>b?a:b;}
inline LL Min(LL a,LL b){return a<b?a:b;}
inline LL read(){
    LL x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
inline void write(LL x){
    if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10),putchar(x%10+'0');
    else putchar(x+'0');
}
#define N 100005
#define M 200005
int n,m,cnt[N],a[N*10],b[N][2];
int edge,to[M],pr[M],hd[N];
inline void addedge(int u,int v){
    to[++edge]=v,pr[edge]=hd[u],hd[u]=edge;
}
inline void print(int k){
    printf("Win\n");
    For(i,1,k) write(a[i]),putchar(' ');
    exit(0);
}
inline void dfs(int dep,int u){
    if(!cnt[u]&&(dep&1)) print(dep-1);
    cross(i,u){
        int v=to[i];
        if(b[v][dep&1]) continue;
        b[v][dep&1]=1,a[dep]=v,dfs(dep+1,v);
    }
}
int idx,dfn[N],low[N],vis[N],top,sta[N],sum;
inline void tarjan(int u){
    vis[sta[++top]=u]=1,dfn[u]=low[u]=++idx;
    cross(i,u){
        int v=to[i];
        if(!dfn[v]) tarjan(v),low[u]=Min(low[u],low[v]);
        else if(vis[v]) low[u]=Min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        int s=0;
        while(sta[top+1]!=u) vis[sta[top--]]=0,s++;
        sum=Max(sum,s);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    n=read(),m=read();
    For(i,1,n){
        cnt[i]=read();
        For(j,1,cnt[i]) addedge(i,read());
    }
    a[1]=read();
    dfs(2,a[1]);
    sum=0,tarjan(a[1]);
    printf(sum>1?"Draw":"Lose");
    return 0;
}