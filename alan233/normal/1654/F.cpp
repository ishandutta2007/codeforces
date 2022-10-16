// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

const int N=1<<18;
const int B1=137;
const int B2=177;
const int mod=998244853;

pii operator + (pii a,pii b){
    return make_pair((a.fir+b.fir)%mod,(a.sec+b.sec)%mod);
}
pii operator * (pii a,pii b){
    return make_pair(1ll*a.fir*b.fir%mod,1ll*a.sec*b.sec%mod);
}

char a[N];
pii f[N][19],pw[N];
int n;

bool cmp(int x,int y){
    if(f[x][n]==f[y][n])return 1;
    per(i,n,1){
        if(f[x][i-1]==f[y][i-1])
            x^=1<<i-1,y^=1<<i-1;
    }    
    return a[x]<a[y];
}

int main(){
    pw[0]=make_pair(1,1);
    scanf("%d%s",&n,a);
    rep(i,0,(1<<n)-1)f[i][0]=make_pair(a[i],a[i]);
    rep(i,1,(1<<n)-1)pw[i]=pw[i-1]*make_pair(B1,B2);
    rep(j,1,n){
        rep(i,0,(1<<n)-1)
            f[i][j]=f[i][j-1]+f[i^1<<j-1][j-1]*pw[1<<j-1];
    }
    int ans=0;
    rep(i,1,(1<<n)-1)if(cmp(i,ans))ans=i;
    rep(i,0,(1<<n)-1)putchar(a[i^ans]);
    puts("");
    return 0;
}