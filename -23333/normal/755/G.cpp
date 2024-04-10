#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
	if (y==0) return 1;
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
const int N=1e6;
const int G=3;

int a[N],b[N],cnt,n,k;
struct fft{
  int l,n,m;
  int r[N],a[N],b[N],w[N],inv[N];
  fft()
  {
    inv[0]=inv[1]=1;
    rep(i,2,N-1) inv[i]=(1ll*inv[mo%i]*(mo-(mo/i)))%mo; 
  }
 /* IL void ntt_init()
  {
    l=0; for (n=1;n<=m;n<<=1) l++;
    for (int i=0;i<n;i++) r[i]=(r[i/2]/2)|((i&1)<<(l-1)); 
  }*/
  IL void clear()
  {
      rep(i,0,n) a[i]=b[i]=0;
  }
/*  void ntt(int *a,int o)
  {
      for (int i=0;i<n;i++) if (i>r[i]) swap(a[i],a[r[i]]);
      for (int i=1;i<n;i<<=1)
      {
          int wn=fsp(G,(mo-1)/(i*2)); w[0]=1;
          rep(j,1,i-1) w[j]=(1ll*w[j-1]*wn)%mo;
          for (int j=0;j<n;j+=(i*2))
            for (int k=0;k<i;k++)
            {
                int x=a[j+k],y=1ll*a[i+j+k]*w[k]%mo;
            //    if (x<0||y<0) cerr<<x<<" "<<y<<endl; 
                a[j+k]=x+y>mo?x+y-mo:x+y; 
            a[i+j+k]=x-y>=0?x-y:x-y+mo;
        //     a[j+k]=(x+y)%mo;
        //     a[i+j+k]=(x-y)%mo;
            }
    }
    if (o==-1)
    {
        reverse(&a[1],&a[n]);
        for (int i=0,inv=fsp(n,mo-2);i<n;i++)
           a[i]=1ll*a[i]*inv%mo;
    }
  }*/
  int ppr[N];
inline void init(){
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
	} std::reverse(f+1,f+x);int invx=mo-(mo-1)/x;
	for(i=f;i!=f+x;i++) *i=1ll**i*invx%mo;
}
  IL void getcj(int *A,int *B,int *C,int len)
  {
    m=len*2; init();
    for (int i=0;i<=len;i++) a[i]=(A[i]%mo+mo)%mo,b[i]=(B[i]%mo+mo)%mo;
    DIF(a,n); DIF(b,n);
    for(int i=0;i<n;i++) a[i]=1ll*a[i]*b[i]%mo;
    DIT(a,n);
    for (int i=0;i<=min(k,m);i++) C[i]=a[i];
    clear();
  }
}F;
map<int,int> M;
int gg[70][280000];
int dp[5010][5010];
void solve(int n)
{
	if (n<=5000||M[n]) return;
	M[n]=++cnt;
//	cerr<<n<<" "<<M[n]<<endl;
	solve(n/2); solve(n-n/2);
	if (n/2-1>0) {solve(n/2-1); solve(n-n/2-1);}

}
void solve2(int n)
{
	int now;
    now=M[n];
	if (n/2<=5000)
	{
	  F.getcj(dp[n/2],dp[n-n/2],a,n-n/2);
    } else F.getcj(gg[M[n/2]],gg[M[n-n/2]],a,min(k,n-n/2+1));
	if (n/2-1>0)
	{
		if (n/2-1<=5000)
		{
			F.getcj(dp[n/2-1],dp[n-n/2-1],b,n-n/2-1);
		} else
		  F.getcj(gg[M[n/2-1]],gg[M[n-n/2-1]],b,min(k-1,n-n/2));
		rep(i,1,k) a[i]=((a[i]+b[i-1])%mo+mo)%mo;
	}
	rep(i,0,k) gg[now][i]=a[i];
	rep(i,0,k) a[i]=b[i]=0; 
}
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>k;
   dp[0][0]=dp[1][0]=dp[1][1]=1;
   rep(i,2,5002) 
     rep(j,0,i)
	 { 
	   dp[i][j]=dp[i-1][j];
	   if (j>=1) (dp[i][j]+=dp[i-1][j-1])%=mo;
	   if (j>=1) (dp[i][j]+=dp[i-2][j-1])%=mo;
     }
   if (n<=5000)
   {
      rep(i,1,k) 
	    if (i<=n) cout<<dp[n][i]<<" "; else cout<<0<<" ";
      return 0;
   }
   solve(n);
   for (auto v:M) 
   {
   	 if (M[v.first-1]&&M[v.first-2])
	 {
	 	int g=M[v.first],g1=M[v.first-1],g2=M[v.first-2];
	 	rep(j,0,min(v.first,k))
	 	{
	 		gg[g][j]=gg[g1][j];
	 		if (j>=1) (gg[g][j]+=gg[g1][j-1])%=mo;
	 		if (j>=1) (gg[g][j]+=gg[g2][j-1])%=mo;
	 	}
	 } else solve2(v.first);
  //   cout<<v.first<<" "<<v.second<<endl;
   }
   int now=M[n];
   rep(i,1,k) cout<<gg[now][i]<<" ";
   cout<<endl;
  // cerr<<cnt<<endl;
   return 0;
}
// 10000 10000
//1000000000 131072
// 1000000000 262140
// 1000000000 262100