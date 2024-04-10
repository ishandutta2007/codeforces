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

template<class T1,class T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<class T1,class T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}

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

const int N=2005;
const int mod=1e9+7;

int a[N],n,h,ans=1;

int main(){
    n=read(),h=read();
    rep(i,1,n+1){
        a[i]=i<=n?read():h;
        if(a[i]>h)return puts("0"),0;
        a[i]=h-a[i];
        if(abs(a[i]-a[i-1])>1)return puts("0"),0;
        if(a[i]==a[i-1]){
            ans=1ll*ans*(a[i-1]+1)%mod;
        }else if(a[i]==a[i-1]-1){
            ans=1ll*ans*a[i-1]%mod;
        }
    }
    print(ans,'\n');
    return 0;
}