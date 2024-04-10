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
#define poly vector<int>
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

const int N=1000005;

struct Edge{
    int to,nxt,val;
}edge[N<<1];
int head[N],etot;
void add(int u,int v,int w){
    edge[++etot]={v,head[u],w};
    head[u]=etot;
}

int n,m;

int calc(int x){
    if(!x)return 0;
    else return __builtin_parity(x);
}

int val[N];bool vis[N];
bool dfs(int u){
    vis[u]=1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to,type=edge[i].val;
        if(!vis[v]){
            val[v]=val[u]^type;
            if(!dfs(v))return 0;
        }else if(val[v]!=(val[u]^type)){
            return 0;
        }
    }
    return 1;
}

void solve(){
    n=read(),m=read();
    rep(i,1,n)head[i]=0;etot=0;
    static int U[N],V[N],W[N];
    rep(i,1,n-1){
        int u=read(),v=read(),w=read();
        U[i]=u,V[i]=v,W[i]=w;
        if(w!=-1){
            w=calc(w);
            add(u,v,w),add(v,u,w);
        }
    }
    rep(i,1,m){
        int u=read(),v=read(),type=read();
        add(u,v,type),add(v,u,type);
    }
    rep(i,1,n)vis[i]=0,val[i]=0;
    rep(i,1,n)if(!vis[i]){
        if(!dfs(i)){
            puts("NO");
            return ;
        }
    }
    puts("YES");
    rep(i,1,n-1){
        printf("%d %d ",U[i],V[i]);
        if(W[i]!=-1)printf("%d\n",W[i]);
        else printf("%d\n",val[U[i]]^val[V[i]]);
    }
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}