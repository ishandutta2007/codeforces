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

const int N=200005;
const ll inf=1e18;

ll a[N],b[N];
int n;

ll calc(ll *a,ll b){
    ll ret=inf;
    rep(i,1,n){
        ckmin(ret,llabs(a[i]-b));
    }
    return ret;
}

void solve(){
    n=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n)b[i]=read();
    ll ans=inf;
    //   ,   
    ckmin(ans,llabs(a[1]-b[1])+llabs(a[n]-b[n]));
    //   ,   
    ckmin(ans,llabs(a[1]-b[1])+calc(b,a[n])+calc(a,b[n]));
    //   ,   
    ckmin(ans,llabs(a[1]-b[n])+llabs(a[n]-b[1]));
    //   ,   
    ckmin(ans,llabs(a[1]-b[n])+calc(b,a[n])+calc(a,b[1]));
    //  ,   
    ckmin(ans,calc(b,a[1])+calc(a,b[1])+llabs(a[n]-b[n]));
    //  ,   
    ckmin(ans,calc(b,a[1])+calc(a,b[n])+llabs(a[n]-b[1]));
    // 
    ckmin(ans,calc(b,a[1])+calc(b,a[n])+calc(a,b[1])+calc(a,b[n]));
    print(ans,'\n');
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}