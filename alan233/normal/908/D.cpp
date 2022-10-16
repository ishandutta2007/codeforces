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

const int mod=1e9+7;
const int inv2=(mod+1)/2;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return res;
}

int dp[1005][1005],K,pa,pb;
int solve(int x,int y){
    if(x+y>=K)return (x+1ll*(mod+1-pb)*qpow(pb))%mod;
    if(~dp[x][y])return dp[x][y];
    else return dp[x][y]=(1ll*pa*solve(x+1,y)+1ll*pb*(solve(x,x+y)+x))%mod;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>K>>pa>>pb;
    int all=qpow(pa+pb);
    pa=1ll*pa*all%mod,pb=1ll*pb*all%mod;
    cout<<solve(1,0)%mod<<'\n';
    return 0;
}