// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

const int N=105;
const int mod=998244353;
const ull MOD=1ull*mod*mod;

int n,m,K;

struct MAT{
    int a[N][N];
    MAT(){
        rep(i,1,n)
            rep(j,1,n)
                a[i][j]=0;
    }
}E,D,dp[3],I;
MAT operator + (MAT a,MAT b){
    rep(i,1,n){
        rep(j,1,n){
            a.a[i][j]=(a.a[i][j]+b.a[i][j])%mod;
        }
    }
    return a;
}
MAT operator - (MAT a,MAT b){
    rep(i,1,n){
        rep(j,1,n){
            a.a[i][j]=(a.a[i][j]+mod-b.a[i][j])%mod;
        }
    }
    return a;
}
MAT operator * (const MAT &a,const MAT &b){
    MAT c;
    rep(i,1,n){
        rep(j,1,n){
            ull tmp=0;
            rep(k,1,n){
                tmp+=1ull*a.a[i][k]*b.a[k][j];
                if(tmp>=MOD)tmp-=MOD;
            }
            c.a[i][j]=tmp%mod;
        }
    }
    return c;
}

struct Info{
    MAT a[2][2];
}ans,res;
Info operator * (Info a,Info b){
    Info cur;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            MAT t;
            for(int k=0;k<2;k++)
                t=t+a.a[i][k]*b.a[k][j];
            cur.a[i][j]=t;
        }
    }
    return cur;
}

int main(){
    n=read(),m=read(),K=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        E.a[u][v]=E.a[v][u]=1;
        D.a[u][u]++,D.a[v][v]++;
    }
    rep(i,1,n)dp[0].a[i][i]=1;
    dp[1]=E*dp[0];
    dp[2]=E*dp[1]-D*dp[0];
    rep(i,1,n)D.a[i][i]=(mod-max(0,D.a[i][i]-1))%mod;
    rep(i,1,n)I.a[i][i]=1;
    if(K<=2){
        int anss=0;
        rep(i,1,n)
            anss=(anss+dp[K].a[i][i])%mod;
        print(anss,'\n');
        return 0;
    }
    K-=2;
    ans.a[0][0]=dp[2],ans.a[1][0]=dp[1];
    res.a[0][0]=E,res.a[0][1]=D;
    res.a[1][0]=I;
    while(K){
        if(K&1){
            ans=res*ans;
        }
        res=res*res;
        K>>=1;
    }
    int anss=0;
    rep(i,1,n)
        anss=(anss+ans.a[0][0].a[i][i])%mod;
    print(anss,'\n');
    return 0;
}