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

const int N=5005;
const int mod=998244353;

char a[N];
int pre[N];
int n,k;

int fac[N],ifac[N];
inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return res;
}
inline void init(int n){
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int C(int n,int m){
    if(n<m||m<0)return 0;else return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}

int main(){
    init(5002);
    scanf("%d%d%s",&n,&k,a+1);
    rep(i,1,n){
        a[i]-='0';
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;
    if(pre[n]>=k){
        rep(l,1,n){
            rep(r,l+1,n){
                if(pre[r]-pre[l-1]<=k){
                    int must=(!a[l])+(!a[r]);
                    ans=(ans+C(r-l-1,pre[r]-pre[l-1]-must))%mod;
                }
            }
        }
    }
    printf("%d\n",(ans+1)%mod);
    return 0;
}