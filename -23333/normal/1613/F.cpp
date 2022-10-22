#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long  
#define IL inline
const int N=1e6+10;
const int mo=998244353;
vector<int> ve[N];
vector<int> ans[N];
ll fsp(int x,int y)
{
    if (y==1) return x;
    ll ans=fsp(x,y/2);
    ans=ans*ans%mo;
    if (y%2==1) ans=ans*x%mo;
    return ans;
}
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
  IL void getcj(int *C,int len)
  {
  //    for (int i=0;i<=len;i++) a[i]=(A[i]%mo+mo)%mo,b[i]=(B[i]%mo+mo)%mo;      
      m=len*2; ntt_init();
      rep(i,0,n) a[i]=(a[i]+mo)%mo,b[i]=(b[i]+mo)%mo;
      DIF(a,n); DIF(b,n);
      for (int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%mo;
      DIT(a,n);
      for (int i=0;i<n;i++) C[i]=a[i];
      clear();
  }
  IL void getinv(int *A,int *B,int len)
  {
    if (len==1) { B[0]=fsp(A[0],mo-2); return; }
    getinv(A,B,(len+1)>>1);
    m=len*2; ntt_init();
    for (int i=0;i<=len;i++) a[i]=A[i],b[i]=B[i];
    DIF(a,n); DIF(b,n);
    for (int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%mo*b[i]%mo;
    DIT(a,n);
    for (int i=0;i<=len;i++) B[i]=((2*B[i]-a[i])%mo+mo)%mo; 
    clear();
  }
  IL void getsqrt(int *A,int *B,int len)
  {
    int inv2=fsp(2,mo-2);
    if (len==1) {B[0]=sqrt(A[0]); return;}
    getsqrt(A,B,(len+1)>>1);
    int C[N]={};
    getinv(B,C,len);
    getcj(A,C,len);
    for (int i=0;i<=len;i++) B[i]=1ll*(C[i]+B[i])%mo*inv2%mo;
  }
  IL void getDao(int *a,int *b,int len)
  {
    for (int i=1;i<=len;i++) b[i-1]=1ll*i*a[i]%mo;
    b[len-1]=0;
  }
  IL void getjf(int *a,int *b,int len)
  {
    for (int i=0;i<=len;i++) b[i+1]=1ll*a[i]*inv[i+1]%mo;
    b[0]=0;
  }
  IL void getln(int *A,int *B,int len)
  {
  //  me(C); me(D);
    getDao(A,C,len);
    getinv(A,D,len);
    getcj(C,D,len);
    getjf(D,B,len);
    rep(i,0,len) C[i]=0,D[i]=0;
  }
  IL void getexp(int *A,int *B,int len)
  {
    if (len==1) {B[0]=1; return;}
    getexp(A,B,(len+1)>>1);
    int C[N];
    getln(B,C,len);
    for(int i=0;i<=len;i++) C[i]=((-C[i]+A[i])%mo+mo)%mo;
    C[0]=(C[0]+1)%mo;
    getcj(C,B,len);
  }
}F;
int sum[N],now[N],a[N],b[N],c[N],d[N],e[N];
ll jc[N],jc2[N];
/*
\prod (1+a[i]x) 
*/ 
void solve(int h,int t,int *a)
{
    if (h==t) return;
    int mid=(h+t)/2;
    solve(h,mid,a); solve(mid+1,t,a);
    rep(i,h,mid) F.a[i-h+1]=a[i];
    rep(i,mid+1,t) F.b[i-mid]=a[i];
    F.a[0]=F.b[0]=1;
    F.getcj(now,(mid-h+2));
    rep(i,h,t) a[i]=now[i-h+1];
}
void dfs(int x,int y)
{
	for (auto v:ve[x])
	  if (v!=y)
	  {
	    dfs(v,x);
	    sum[x]++;
	  }
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	jc[0]=1;
	rep(i,1,n) jc[i]=1ll*jc[i-1]*i%mo;
	rep(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		ve[x].push_back(y);
		ve[y].push_back(x); 
	}
	dfs(1,0);
	solve(1,n,sum);
	sum[0]=1;
	ll ans=0;
	rep(i,0,n)
	{
		if(i%2==0) (ans+=jc[n-i]*sum[i])%=mo;
		else (ans-=jc[n-i]*sum[i])%=mo;
	}
	ans=(ans+mo)%mo;
	cout<<ans<<endl;
	return 0;
}