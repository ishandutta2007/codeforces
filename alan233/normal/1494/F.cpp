#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=3005;

struct ee{int u,v;}e[N];
vector<int>E[N];
int deg[N],n,m;

struct Edge{int to,nxt;}edge[N<<1];
int head[N],vis[N],etot;
void add(int u,int v){
    edge[++etot]={v,head[u]},head[u]=etot;
}

vector<int>odds;
int allE,odd;
void dfs(int u){
    vis[u]=1;
    int dg=0;
    for(int i=head[u];i;i=edge[i].nxt){
        allE++;
        int v=edge[i].to;
        if(!vis[v])dfs(v); 
        dg^=1;
    }
    if(dg)odd++,odds.pb(u);
}

int pat[N],len;
void dfs1(int u){
    for(int &i=head[u];i;i=edge[i].nxt){
        if(vis[i/2])continue;
        vis[i/2]=1;
        int v=edge[i].to;
        dfs1(v);
        pat[++len]=v;
    }
}

void sol(int c,int keepu,int keepv){
    rep(i,1,n)head[i]=0;
    rep(i,1,max(n,m))vis[i]=0;
    etot=1,allE=odd=0;odds.clear();
//    printf("now sol c=%d,keepu=%d,keepv=%d\n",c,keepu,keepv);
    rep(i,1,m){
        if(e[i].v==c)swap(e[i].u,e[i].v);
        if(e[i].u==c){
            if((~deg[e[i].v]&1)||e[i].v==keepv){
                add(e[i].u,e[i].v);
                add(e[i].v,e[i].u);
                allE-=2;
            }
        }else{
            add(e[i].u,e[i].v);
            add(e[i].v,e[i].u);
            allE-=2;
        }
    }
//    printf("cureent allE=%d\n",allE);
    dfs(c);
//    printf("fuck allE=%d,odd=%d\n",allE,odd);
    if(allE||odd>2)return;
    int rt=0;
    if(!odd)rt=c;
    else{
//        printf("SZ=%d\n",SZ(odds));
//        assert(SZ(odds)==2);
        bool flag=0;
        for(auto it:odds)if(it!=c)rt=it;else flag=1;
        if(!flag)return;
    }
    fprintf(stderr,"When c=%d,keepu=%d,keepv=%d,rt=%d\n",c,keepu,keepv,rt);
    rep(i,1,max(n,m))vis[i]=0;
    len=0,dfs1(rt),pat[++len]=rt;
    vector<int>ans;
    per(i,len,1)ans.pb(pat[i]);ans.pb(-1);
    for(auto j:E[c]){
        if(j==keepv||(~deg[j]&1))continue;
        ans.pb(j),ans.pb(c);
    }
    printf("%d\n",SZ(ans));for(auto v:ans)printf("%d ",v);puts("");
    exit(0);
}
int main(){
    n=read(),m=read();
    rep(i,1,m){
        e[i].u=read(),e[i].v=read();
        E[e[i].u].pb(e[i].v);
        E[e[i].v].pb(e[i].u);
        deg[e[i].u]^=1,deg[e[i].v]^=1;
    }    
    rep(i,1,n){
        sol(i,0,0);
        for(auto j:E[i])sol(i,i,j);     
    }
    return puts("0"),0;
}