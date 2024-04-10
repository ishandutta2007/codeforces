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

const int N=305;

struct ZZ{
    int a,b,c;
};
vector<ZZ>op;

vector<int>adj[N];

int a[N],b[N];
int n,m;

vector<int>tmp;
vector<int>pat[N][N];
int S;
bool vis[N];
void dfs(int u){
    tmp.pb(u);
    pat[S][u]=tmp;
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v])continue;
        dfs(v);    
    }
    tmp.pop_back();
}

void fuck(int a,int b,int c){
    ::a[a]-=c,::a[b]+=c;
    op.pb({a,b,c});
}

void pour(int u,int v,int w){
    if(u==v||!SZ(pat[u][v]))return;
//    assert(SZ(pat[u][v])>=1);
    int pre=pat[u][v][SZ(pat[u][v])-2];
    int flow=min(a[pre],w);
    fuck(pre,v,flow);
    pour(u,pre,w);
    if(flow!=w){
        fuck(pre,v,w-flow);
    }
}

int main(){
    n=read(),read(),m=read();
    ll _=0;
    rep(i,1,n)a[i]=read(),_+=a[i];
    rep(i,1,n)b[i]=read(),_-=b[i];
    rep(i,1,m){
        int u=read(),v=read();
        adj[u].pb(v),adj[v].pb(u);
    }
    if(_){puts("NO");return 0;}
    queue<int>q1,q2;
    rep(i,1,n){
        if(a[i]<b[i])q1.push(i);
        if(a[i]>b[i])q2.push(i);
    }
    rep(i,1,n){
        memset(vis,0,sizeof(vis));
        S=i,dfs(i);
    }
//    cerr<<"!\n";
    /*
    , 
    */
    while(!q1.empty()&&!q2.empty()){
        int u=q1.front(),v=q2.front();
        if(b[u]-a[u]==a[v]-b[v]){
            pour(v,u,a[v]-b[v]);
            q1.pop(),q2.pop();
        }else if(b[u]-a[u]>a[v]-b[v]){
            pour(v,u,a[v]-b[v]);
            q2.pop();
        }else{
            pour(v,u,b[u]-a[u]);
            q1.pop();
        }
    }
    rep(i,1,n)if(a[i]!=b[i]){puts("NO");return 0;}
    print(SZ(op),'\n');
    for(auto it:op)printf("%d %d %d\n",it.a,it.b,it.c);
    return 0; 
}