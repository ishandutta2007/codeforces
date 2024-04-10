// Author: wlzhouzhuan
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

const int M=10000005;
const int N=150005;
const int mod=998244353;

int pw[N],X,n;

int ch[M][2],sz[M],tot=1;
void ins(int x){
    int rt=1;
    for(int i=29;i>=0;i--){
        int &t=ch[rt][x>>i&1];
        if(!t)t=++tot;
        rt=t,sz[rt]++;
    }
}

int get(int u){
    return pw[sz[u]]-1;
}
int dfs(int dep,int u,int v){
    if(dep<0)return u==v?pw[sz[u]]:1ll*pw[sz[u]]*pw[sz[v]]%mod;
    if(!u||!v)return pw[sz[u]+sz[v]];
    if(u==v){
        if(X>>dep&1)return dfs(dep-1,ch[u][0],ch[u][1]);
        else return (dfs(dep-1,ch[u][0],ch[u][0])+dfs(dep-1,ch[u][1],ch[u][1])-1)%mod;
    }else{
        if(X>>dep&1)return 1ll*dfs(dep-1,ch[u][0],ch[v][1])*dfs(dep-1,ch[u][1],ch[v][0])%mod;
        else return (dfs(dep-1,ch[u][0],ch[v][0])+dfs(dep-1,ch[u][1],ch[v][1])-1+1ll*get(ch[u][0])*get(ch[u][1])+1ll*get(ch[v][0])*get(ch[v][1]))%mod;
    }
}

int main(){
    n=read(),X=read();
    pw[0]=1;rep(i,1,n)pw[i]=2*pw[i-1]%mod;
    rep(i,1,n){
        int x=read();
        ins(x);
    }
//    printf("tot=%d\n",tot);
    int ans=dfs(29,1,1);
    printf("%d\n",(ans+mod-1)%mod);
    return 0;
}