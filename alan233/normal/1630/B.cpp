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

int a[N],cnt[N];
int n,K;

void solve(){
    n=read(),K=read();
    memset(cnt,0,4*(n+1));
    rep(i,1,n)a[i]=read(),cnt[a[i]]+=1;
    int now=-n,ans=INT_MAX,ansl,ansr;
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&now<K)now+=2*cnt[j++];
        if(now>=K){
            if(ans>j-i)ans=j-i,ansl=i,ansr=j;
        }
        now-=2*cnt[i];
    }
    --ansr;
    printf("%d %d\n",ansl,ansr);
    vector<pii>anss;
    now=0;
    int las=0,qaq=1;
    rep(i,1,n){
        if(a[i]>=ansl&&a[i]<=ansr)now++;
        else now--;
        if((now==qaq&&qaq<K)||i==n){
            anss.pb({las+1,i});
            las=i,qaq++;
        }
    }
    for(auto it:anss)printf("%d %d\n",it.fir,it.sec);
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}