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

const int N=300005;

int a[N],f[N],n,q,mod;
int fuck,dlts;

inline void Push(int x,int dlt){
    dlt=dlts*dlt;
    if(a[x])fuck--;
    a[x]=(a[x]+dlt)%mod;
    if(a[x])fuck++;
}

int main(){
    scanf("%d%d%d",&n,&q,&mod);
    f[1]=f[2]=1;rep(i,3,n)f[i]=(f[i-1]+f[i-2])%mod;
    rep(i,1,n)a[i]=read();
    rep(i,1,n)a[i]=(a[i]-read())%mod;
    per(i,n+2,1){
        if(i>1)a[i]=(a[i]-a[i-1])%mod;
        if(i>2)a[i]=(a[i]-a[i-2])%mod;
        if(a[i])fuck++;
    }
    // rep(i,1,n+2){
    //     printf("a[%d]=%d\n",i,a[i]);
    // }
    while(q--){
        char opt[3];scanf("%s",opt);
        int l=read(),r=read();
        if(opt[0]=='A')dlts=1;else dlts=-1;
        Push(l,f[1]),Push(l+1,f[2]-f[1]);
        Push(r+1,(-f[r-l+1]-f[r-l])%mod),Push(r+2,-f[r-l+1]);
        puts(fuck?"NO":"YES");
        // rep(i,1,n+2)printf("a[%d]=%d\n",i,a[i]);
    }
    return 0;
}