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

const int N=200005;
const int mod=1e9+7;
const int inv2=(mod+1)/2;

inline void add(int &x,int y){
    x+=y;if(x>=mod)x-=mod;
}

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return res;
}

struct Line{
    int l,r,type;
    friend bool operator < (const Line &x,const Line &y){
        return x.r!=y.r?x.r<y.r:x.l>y.l;
    }
}a[N],b[N],c[N];
int K,n,m;

void sol(Line *a,int &n){
    sort(a+1,a+n+1);
    int _n=0;
    rep(i,1,n){
        if(!_n||a[i].l>a[_n].l)
            a[++_n]=a[i];
    }
    n=_n;
}

int coef[2][N];
int dp[N],sum[N];

inline int get(int x){
    int l=0,r=n+m;
    while(l<r){
        int mid=l+r+1>>1;
        if(c[mid].r<x)l=mid;
        else r=mid-1;
    }    
    return l;
}

int main(){
    K=read(),n=read(),m=read();
    rep(i,1,n)a[i].l=read(),a[i].r=read(),a[i].type=0;
    sol(a,n);
    rep(i,1,m)b[i].l=read(),b[i].r=read(),b[i].type=1;
    sol(b,m);
    merge(a+1,a+n+1,b+1,b+m+1,c+1);
//    rep(i,1,n+m){
//        printf("%d %d %d\n",c[i].l,c[i].r,c[i].type);
//    }
    int ans=1;
    sum[0]=1;
    rep(i,1,n+m){
        int cf1=(mod-qpow(inv2,c[i].r-c[i].l+1))%mod;
        int cf2=(mod-qpow(inv2,c[i].r))%mod;
        int pos=get(c[i].l);
        add(dp[i],1ll*cf1*sum[pos]%mod);
        add(dp[i],1ll*cf2*(coef[c[i].type][i-1]+mod-coef[c[i].type][pos])%mod);
//        printf("dp[%d]=%d\n",i,dp[i]);
        add(ans,dp[i]);
        
//        printf("%d %d %d: %d\n",c[i].l,c[i].r,c[i].type,pos);
        sum[i]=(sum[i-1]+dp[i])%mod;
        coef[0][i]=coef[0][i-1],coef[1][i]=coef[1][i-1];
        add(coef[c[i].type][i],1ll*dp[i]*qpow(2,c[i].r)%mod);
    }
    printf("%d\n",1ll*ans*qpow(2,K)%mod);
    return 0;
}