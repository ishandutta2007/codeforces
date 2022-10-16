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

const int N=100005;

struct qq{int u,k,id,real_u,ans;}q[N];
vector<int>adj[N];int n,m;

vector<pii>ask1[N],ask2[N];
int dep[N],stk[N],top;
void dfs1(int u,int fa){
    stk[++top]=u,dep[u]=dep[fa]+1;
    for(auto it:ask1[u])q[it.sec].real_u=top>it.fir?stk[top-it.fir]:0;
    for(auto v:adj[u])dfs1(v,u);
    top--; 
}
int buc[N];
void dfs2(int u){
    buc[dep[u]]++;
    for(auto it:ask2[u])q[it.sec].ans-=buc[dep[u]+it.fir];
    for(auto v:adj[u])dfs2(v);
    for(auto it:ask2[u])q[it.sec].ans+=buc[dep[u]+it.fir];
}

int main(){
    n=read();
    rep(i,1,n)adj[read()].pb(i);
    m=read();
    rep(i,1,m){
        q[i].u=read(),q[i].k=read(),q[i].id=i;
        ask1[q[i].u].pb({q[i].k,q[i].id});
    }
    dfs1(0,-1);
    rep(i,1,m){
//        fprintf(stderr,"i=%d,real_u=%d\n",i,q[i].real_u);
        if(q[i].real_u)ask2[q[i].real_u].pb({q[i].k,q[i].id});
    }
    dfs2(0);
    rep(i,1,m)print(max(0,q[i].ans-1), " \n"[i==m]);
    return 0;
}