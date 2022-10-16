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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ull a[N];
int b[N],n,m;
map<ull,pair<ll,ll>> mp; 

int main(){
    n=read(),m=read();
    rep(i,1,n){
        int l=read(),r=read();
        ull val=rng();
        a[l+1]^=val,a[r+1]^=val;
        b[l]++,b[r+1]--;
    }
    ll ans=0,keep=0;
    rep(i,1,m)a[i]^=a[i-1];
    rep(i,1,m){
        a[i]^=a[i-1],b[i]+=b[i-1];
        if(!b[i])keep++;
        else keep=0;
        ans-=keep*(keep+1)/2;
        pair<ll,ll> it=mp[a[i]];
        it.fir++;
        it.sec+=i-1;
        mp[a[i]]=it;
        ans+=it.fir*i-it.sec;
    }
    print(ans,'\n');
    return 0;
}