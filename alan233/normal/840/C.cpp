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

const int N=305;
const int mod=1e9+7;

inline int qpow(int a,int b=mod-2){
    int res=1;
    while(b>0){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;b>>=1;
    }
    return res;
}

int fac[N],ifac[N];
int a[N],C[N][N],n;

int gao(int x){
    int y=1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            bool flg=0;
            while(x%i==0)x/=i,flg^=1;
            if(flg)y*=i;
        }
    }    
    if(x>1)y*=x;
    return y;
}

#define poly vector<int>
vector<poly>sol;
poly operator * (poly a,poly b){
    poly c(SZ(a)+SZ(b)-1);
    rep(i,0,SZ(a)-1)rep(j,0,SZ(b)-1)c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mod;
    return c;
}
poly solve(int l,int r){
    if(l==r)return sol[l];
    int mid=l+r>>1;
    return solve(l,mid)*solve(mid+1,r);
}

int main(){
    n=read();
    rep(i,1,n)a[i]=gao(read());
    sort(a+1,a+n+1);
//    rep(i,1,n)printf("a[%d]=%d\n",i,a[i]);
    
    fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
    ifac[0]=1;rep(i,1,n)ifac[i]=qpow(fac[i]);
    C[0][0]=1;
    rep(i,1,n){
        C[i][0]=1;
        rep(j,1,i)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    
    for(int i=1;i<=n;i++){
        int j=i;while(j<n&&a[j]==a[j+1])++j;
        int len=j-i+1;
        poly f(len+1);
        for(int l=1;l<=len;l++){
            f[l]=1ll*C[len-1][l-1]*fac[len]%mod*ifac[l]%mod;
            if((len-l)&1)f[l]=(mod-f[l])%mod;
        }
//        for(auto it:f)printf("%d ",it);puts("");
        sol.pb(f);
        i=j;
    } 
    poly ans=solve(0,SZ(sol)-1);
//    for(auto it:ans)printf("%d ",it);puts("");
    int ANS=0;
    rep(i,1,SZ(ans)-1)
        ANS=(ANS+1ll*fac[i]*ans[i])%mod;
    print(ANS,'\n');
    return 0;
}