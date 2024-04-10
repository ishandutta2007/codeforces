//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

//#include <immintrin.h>
//#include <emmintrin.h>
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

const int N=6e5;
ll jc[N],jc2[N];
ll C(int n,int m)
{
	return jc[n]*jc2[m]%mo*jc2[n-m]%mo; 
}
#define mid ((h+t)/2)
struct sgt{
	int v[N*4],lazy[N*4],pp[N*4];
	void down(int x,int h,int t)
	{
		if (pp[x])
		{
			pp[x*2]=1; pp[x*2+1]=1;
			v[x*2]=mid-h+1; v[x*2+1]=t-mid;;
			pp[x]=0;
			lazy[x*2]=0; lazy[x*2+1]=0;
		}
		if (lazy[x])
		{ 
		  lazy[x*2]=lazy[x*2+1]=1;
		  v[x*2]=v[x*2+1]=0;
		  lazy[x]=0;
	    }
	}
	void b(int x,int h,int t)
	{
		v[x]=t-h+1; lazy[x]=0;
		if (h==t) return;
		b(x*2,h,mid); b(x*2+1,mid+1,t);
	}
	int q(int x,int h,int t,int k)
	{
		if (k==0) return 1e9;
		if (h==t) return h;
		down(x,h,t); 
		if (v[x*2+1]>=k) return q(x*2+1,mid+1,t,k);
		else return q(x*2,h,mid,k-v[x*2+1]);
	}
	void g(int x,int h,int t,int pos)
	{
		if (h==t) { v[x]=0; return; }
		down(x,h,t); 
		if (pos<=mid) g(x*2,h,mid,pos);
		else g(x*2+1,mid+1,t,pos);
		v[x]=v[x*2]+v[x*2+1];
	}
	void p(int x,int h,int t,int k)
	{
		if (!k) return;
		if (h==t)
		{
			v[x]=0; return;
		}
		down(x,h,t);
		if (v[x*2+1]>=k) p(x*2+1,mid+1,t,k);
		else
		{
			
			p(x*2,h,mid,k-v[x*2+1]);
			v[x*2+1]=0; lazy[x*2+1]=1;
		}
		v[x]=v[x*2]+v[x*2+1];
	}
}S;
int a[N],b[N],f[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   int nn=5e5;
   jc[0]=jc2[0]=1;
   rep(i,1,nn) jc[i]=jc[i-1]*i%mo;
   jc2[nn]=fsp(jc[nn],mo-2);
   dep(i,nn-1,1) jc2[i]=jc2[i+1]*(i+1)%mo; 
   cin>>T;
   while (T--)
   {
   	  int n,m;
   	  cin>>n>>m;
   	  S.v[1]=n; S.pp[1]=1; S.lazy[1]=0;
   	  rep(i,1,m)
   	  {
   	  	cin>>a[i]>>b[i];
   	  }
   	  int cnt=0;
   	  a[m+1]=n+1;
   	  a[0]=0;
   	  dep(i,m,1)
   	  {
   	  	int kk=a[i+1]-a[i]-1;
   	  	if (kk) S.p(1,1,n,kk);
   	    int k=S.q(1,1,n,a[i]-b[i]+1);
   	    int k2=S.q(1,1,n,a[i]-b[i]);
   	    if (k2==k+1)  cnt++;
   	    S.g(1,1,n,k);
	  }
	  int n2=n-cnt+n-1;
	  cout<<C(n2,n)<<endl;
   }
   return 0;
}