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

const int N=100005;

ll dp[N];
int a[N],b[N],n;
int q[N],ql=1,qr;

double slope(int i,int j){
    return (dp[j]-dp[i])/1./(b[i]-b[j]);
}

int main(){
    n=read();rep(i,1,n)a[i]=read();rep(i,1,n)b[i]=read();
    q[++qr]=0;
    rep(i,1,n){
        while(ql<qr&&slope(q[ql],q[ql+1])<a[i])ql++;
        int j=q[ql];dp[i]=dp[j]+1ll*a[i]*b[j];
        while(ql<qr&&slope(q[qr-1],q[qr])>slope(q[qr],i))qr--;
        q[++qr]=i;
    }
    print(dp[n],'\n');
    return 0;
}