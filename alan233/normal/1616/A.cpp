// Author: wlzhouzhuan
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

void solve(){
    int n=read();
    int cnt[205];
    memset(cnt,0,sizeof(cnt));
    rep(i,1,n){
        int x=read();
        cnt[x+100]++;
    }
    int ans=0;
    if(cnt[100])ans++;
    rep(i,1,100){
        if(cnt[100-i]+cnt[100+i]>=2)ans+=2;
        else if(cnt[100-i]||cnt[100+i])ans++;
    }
    printf("%d\n",ans);
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}