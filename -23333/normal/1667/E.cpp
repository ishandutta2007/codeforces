#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
inline ll rd(){
    ll x=0;char c=getchar();bool f=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return f?-x:x;
}
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
    return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void maxa(T &x,T y)
{
    if (y>x) x=y;
}
template<class T>void mina(T &x,T y)
{
    if (y<x) x=y;
}
template<class T>void read(T &x)
{
    int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
    while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=998244353;
ll fsp(int x,int y)
{
    if (y==1) return x;
    ll ans=fsp(x,y/2);
    ans=ans*ans%mo;
    if (y%2==1) ans=ans*x%mo;
    return ans;
}
struct cp {
    ll x,y;
    cp operator +(cp B)
    {
        return (cp){x+B.x,y+B.y};
    }
    cp operator -(cp B)
    {
        return (cp){x-B.x,y-B.y};
    }
    ll operator *(cp B)
    {
        return x*B.y-y*B.x;
    }
    int half() { return y < 0 || (y == 0 && x < 0); }
};
struct re{
    int a,b,c;
};
const int N=6e5;
const int G=3;
int f[N],g[N],n;
struct fft{
  int l,n,m;
  int a[N],b[N],inv[N];
  int C[N],D[N];
  fft()
  {
    inv[0]=inv[1]=1;
    rep(i,2,N-1) inv[i]=(1ll*inv[mo%i]*(mo-(mo/i)))%mo; 
  }
  IL void clear()
  {
      rep(i,0,n) a[i]=b[i]=0;
  }
  int ppr[N];
  inline void ntt_init(){
    int lg=0,x;
    for (x=1;x<=m;x*=2) lg++;
    n=x;
    ppr[0]=1;ppr[x]=fsp(31,1<<(21-lg));
    for(int i=x>>1;i;i>>=1) ppr[i]=1ll*ppr[i<<1]*ppr[i<<1]%mo;
    for(int i=1;i<x;i++) ppr[i]=1ll*ppr[i&(i-1)]*ppr[i&-i]%mo;
  }
  inline int del(const int x){
    return x>=mo?x-mo:x;
  }
  inline void DIF(int *f,const int x){
    int len,hl,uni,*s,*i,*w;
    for(len=x,hl=x>>1;hl;len=hl,hl>>=1){
        for(s=f,w=ppr;s!=f+x;s+=len,w++){
            for(i=s;i<s+hl;i++){
                uni=1ll**(i+hl)**w%mo;
                *(i+hl)=del(*i+mo-uni);
                *i=del(*i+uni);
            }
        }
    }
  }
  inline void DIT(int *f,const int x){
    int len,hl,uni,*s,*i,*w;
    for(len=2,hl=1;len<=x;hl=len,len<<=1){
        for(s=f,w=ppr;s!=f+x;s+=len,w++){
            for(i=s;i!=s+hl;i++){
                uni=*i;
                *i=del(uni+*(i+hl));
                *(i+hl)=1ll*(uni+mo-*(i+hl))**w%mo;
            }
        }
    }
    reverse(f+1,f+x);int invx=mo-(mo-1)/x;
    for(i=f;i!=f+x;i++) *i=1ll**i*invx%mo;
  }
  IL void getcj(int *A,int *B,int len)
  {
    m=len*2; ntt_init();
    for (int i=0;i<=len;i++) a[i]=(A[i]%mo+mo)%mo,b[i]=(B[i]%mo+mo)%mo;
    DIF(a,n); DIF(b,n);
    for(int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%mo;
    DIT(a,n);
    for (int i=0;i<=len;i++) B[i]=a[i];
    clear();
  }
}F;
ll jc[N],jc2[N],ans[N];
int main()
{
   ios::sync_with_stdio(false);
   cin>>n;
   jc[0]=jc2[0]=1;
   rep(i,1,n) jc[i]=jc[i-1]*i%mo,jc2[i]=jc2[i-1]*F.inv[i]%mo;
   int t=(n-1)/2;
   rep(i,t,n-2) f[i]=jc[n-i-2];
   rep(i,0,n) g[i]=jc2[i];
   F.getcj(f,g,n);
   rep(i,1,n) ans[i]=g[n-i]*jc[n-i]%mo*(i-1)%mo;
   ans[1]=jc[n-1];
   memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
   t++;
   rep(i,t,n-1) f[i]=jc[n-i-1]*F.inv[i]%mo;
   rep(i,0,n) g[i]=jc2[i];
   F.getcj(f,g,n);
   rep(i,1,n) ans[i]-=g[n-i]*jc[n-i]%mo;
   rep(i,1,n) cout<<(ans[i]%mo+mo)%mo<<" "; 
   return 0;
}