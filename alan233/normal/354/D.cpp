// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
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

const int N=100005;

vector<int>adj[N];
int f[2][780],g[2][780];
int n,K;

int main(){
    n=read(),K=read();
    rep(i,1,K){
        int x=read(),y=read();
        adj[y].pb(n+1-x);
    }    
    rep(i,1,n)sort(adj[i].begin(),adj[i].end());
    int lim=sqrt(6*K)+1;
    memset(f,0x3f,sizeof(f));
    memset(g,0x3f,sizeof(g));
    f[0][0]=0;
    rep(i,0,lim)g[0][i]=0;
    rep(i,1,n){
        int head=0;
        rep(j,0,min(lim,n+1-i)){
            f[i&1][j]=0x3f3f3f3f;
            if(j<lim)f[i&1][j]=f[~i&1][j+1];
            ckmin(f[i&1][j],g[~i&1][j]+(j?j*(j+1)/2+2:0));
            while(head<SZ(adj[i])&&adj[i][head]<=j)++head;
            f[i&1][j]+=(SZ(adj[i])-head)*3;
//            printf("dp[%d][%d]=%d\n",i,j,f[i][j]);
        }
        rep(j,0,min(lim,n+1-i)){
            g[i&1][j]=f[i&1][j];
            if(j)ckmin(g[i&1][j],g[i&1][j-1]);
        }
    }
    print(g[n&1][1],'\n');
    return 0;
}