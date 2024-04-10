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

const int N=200005;

map<int,int> cnt;
int a[N],n;

bool check(ll x){
    if(cnt[x])return --cnt[x],1;
    if(x==1||check(x/2))return x==1?0:check((x+1)/2);
    return 0;
}

void solve(){
    cnt.clear();
    n=read();
    ll sum=0;
    rep(i,1,n)a[i]=read(),sum+=a[i],cnt[a[i]]++;
    if(!check(sum)){
        puts("NO");
        return;
    }
    sum=0;
    for(auto [x,y]:cnt)sum+=y;
    if(sum<=1)puts("YES");
    else puts("NO");
}
int main(){
    int T=read();
    while(T--)solve();
    return 0;
}