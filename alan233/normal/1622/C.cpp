#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back

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

const int N=200005;

ll K;
int n;
ll a[N];

void solve(){
    scanf("%d%lld",&n,&K);
    ll all=0;
    rep(i,1,n)scanf("%lld",&a[i]),all+=a[i];
    if(all<=K){
        puts("0");
        return;
    }
    all-=K;
    sort(a+1,a+n+1);
    ll suf=0,ans=5e18;
    per(i,n+1,2){
        if(i<=n)suf+=a[i]-a[1];
        if(suf>=all)ckmin(ans,n-i+1);
        else ckmin(ans,(all-suf-1)/(n-i+2)+1+n-i+1);
    }
    printf("%lld\n",ans);
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}