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

const int N=200005;

vector<int>rem; 
int n,cnt[N],a[N];

void solve(){
    n=read();
    rep(i,0,n)cnt[i]=0;
    rep(i,1,n){
        a[i]=read();
        cnt[a[i]]++;
    }
    rem.clear();
    ll ans=0;
    rep(i,0,n){
        if(i){
            rep(_,1,cnt[i-1])rem.pb(i-1);
        }
        if(i&&!cnt[i-1]){
            if(!SZ(rem)){
                while(i<=n){
                    printf("-1 ");
                    i++;
                }
                puts("");
                return;
            }
            ans+=i-1-rem.back();
            rem.pop_back();
        }else if(i){
            rem.pop_back();
        }
        printf("%lld ",ans+cnt[i]);
    }
    puts("");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}