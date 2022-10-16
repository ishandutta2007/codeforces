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

#define int long long

const int N=200005;
const int inf=2e9;

int a[N],n,X;

void solve(){
    n=read(),X=read();
    int mn=inf,mx=0;ll ans=0;
    rep(i,1,n){
        a[i]=read();
        ckmin(mn,a[i]),ckmax(mx,a[i]);
        if(i>1)ans+=abs(a[i]-a[i-1]);
    }
    int z1[3],z2[3];
    z1[0]=a[1]-1;
    z1[1]=inf;
    z1[2]=a[n]-1;
    rep(i,1,n-1)ckmin(z1[1],2*(min(a[i],a[i+1])-1));
    z2[0]=X-a[1];
    z2[1]=inf;
    z2[2]=X-a[n];
    rep(i,1,n-1)ckmin(z2[1],2*(X-max(a[i],a[i+1])));
    if(mn>1&&mx<X){
        ll anss=inf;
        rep(i,0,2)
            rep(j,0,2){
                if(i==0&&j==0)continue;
                if(i==2&&j==2)continue;
                ckmin(anss,z1[i]+z2[j]);
            }
        print(anss+ans,'\n');
    }else if(mn>1){
        print(ans+min({z1[0],z1[1],z1[2]}),'\n');
    }else if(mx<X){
        print(ans+min({z2[0],z2[1],z2[2]}),'\n');
    }else{
        print(ans,'\n');
    }
    

}

signed main(){
    int T=read();
    while(T--)solve();
    return 0;
}