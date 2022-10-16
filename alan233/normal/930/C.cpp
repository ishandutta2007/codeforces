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

const int N=100005;
int d[N],n,m;

struct fen{
    int c[N];
    void ini(){
        rep(i,1,m+1)c[i]=0;
    }
    void add(int x,int dlt){
        while(x<=m+1){
            ckmax(c[x],dlt);
            x+=x&-x;
        }
    }    
    int qry(int x){
        int ret=0;
        while(x){
            ckmax(ret,c[x]);
            x^=x&-x;
        }
        return ret;
    }
}tr;
int f[N],g[N];

int main(){
    n=read(),m=read();
    rep(i,1,n){
        int l=read(),r=read();
        d[l]++,d[r+1]--;
    }    
    rep(i,1,m)d[i]+=d[i-1];
    rep(i,1,m)d[i]++;
    rep(i,1,m){
        f[i]=tr.qry(d[i])+1;
        tr.add(d[i],f[i]);
    }
    tr.ini();
    int ans=0;
    per(i,m,1){
        g[i]=tr.qry(d[i])+1;
        tr.add(d[i],g[i]);
        ckmax(ans,f[i]+g[i]-1);
    }
    cout<<ans;
    return 0;
}