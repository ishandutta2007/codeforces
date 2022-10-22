#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
#define mep(x,y) memcpy(x,y,sizeof(y))
namespace IO{
	char ss[1<<24],*A=ss,*B=ss;
	IL char gc()
	{
		return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
	}
	template<class T>void read(T &x)
	{
		rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
		while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f;
	}
	char sr[1<<24],z[20]; int Z,C=-1;
	template<class T>void wer(T x)
	{
		if (x<0) sr[++C]='-',x=-x;
		while (z[++Z]=x%10+48,x/=10);
		while (sr[++C]=z[Z],--Z);
	}
	IL void wer1() { sr[++C]=' ';}
	IL void wer2() { sr[++C]='\n';}
	template<class T>IL void maxa(T &x,T y) { if (x<y) x=y;} 
	template<class T>IL void mina(T &x,T y) { if (x>y) x=y;}
	template<class T>IL T MAX(T x,T y) {return x>y?x:y;}
	template<class T>IL T MIN(T x,T y) {return x<y?x:y;}
};
using namespace IO;
const int N=1.1e6;
int a[N],f[N],cj[N],n;
const int mo=1e9+7;
int main()
{
	read(n);
	rep(i,1,n) read(a[i]),f[a[i]]++;
	cj[0]=1;
	rep(i,1,1e6) cj[i]=cj[i-1]*2%mo;
	rep(i,1,20)
	  dep(j,1e6,1)
	    if ((j>>(i-1))&1) f[j^(1<<(i-1))]+=f[j];
	rep(i,1,1e6) f[i]=(cj[f[i]]-1)%mo;
	rep(i,1,20)
	  dep(j,1e6,1)
	    if ((j>>(i-1))&1) (f[j^(1<<(i-1))]-=f[j])%=mo;
	int ans=(cj[n]-1)%mo;
	rep(i,1,1e6) (ans-=f[i])%=mo;
	ans=(ans+mo)%mo;
	cout<<ans<<endl;
	return 0; 
}