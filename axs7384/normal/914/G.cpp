#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int mod=1e9+7,N=150005;//,M=8000005;
const double pi=acos(-1.0);
int n,ans,X,m,inv2,f[N];
ll g[N];
//int pos[N];
inline int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
inline void read(int &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
// inline void pre_work()
// {
// 	int len=1<<23,l=23;
// 	for (int i=1;i<len;++i)
// 		pos[i]=(pos[i/2]/2)|((i&1)<<(l-1));
// }
// struct clx
// {
// 	double r,i;
// 	clx operator*(const clx &a)
// 	{
// 		return (clx){r*a.r-i*a.i,r*a.i+i*a.r};
// 	}
// 	clx operator+(const clx &a)
// 	{
// 		return (clx){r+a.r,i+a.i};
// 	}
// 	clx operator-(const clx &a)
// 	{
// 		return (clx){r-a.r,i-a.i};
// 	}
// 	clx operator/(const int &a)
// 	{
// 		return (clx){r/(double)a,i/(double)a};
// 	}
// }x[M],y[M],w,unit,tmp;
// inline void dft(clx *a,int n,int opt)
// {
// 	for (int i=1;i<n;++i)
// 		if (i<pos[i])
// 			swap(a[i],a[pos[i]]);
// 	for (int d=1;d<n;d*=2)
// 	{
// 		unit=(clx){cos(pi/d),sin(pi/d)*opt};
// 		for (int i=0;i<n;i+=d*2)
// 		{
// 			w=(clx){1,0};
// 			for (int j=0;j<d;++j,w=w*unit)
// 			{
// 				tmp=a[i+j+d]*w;
// 				a[i+j+d]=a[i+j]-tmp;
// 				a[i+j]=a[i+j]+tmp;
// 			}
// 		}
// 	}
// 	if (opt==-1)
// 	{
// 		for (int i=0;i<n;++i)
// 			a[i]=a[i]/n;
// 	}
// }
// inline int low_bit(int x)
// {
// 	return x&(-x);
// }
struct poly
{
	int a[N],len;
	// poly operator*(const poly &b)
	// {
	// 	for (int i=0;i<len;++i)
	// 	{
	// 		x[i].r=(double)a[i];
	// 		y[i].r=(double)b.a[i];
	// 	}
	// 	dft(x,len,1);
	// 	dft(y,len,1);
	// 	for (int i=0;i<len;++i)
	// 		x[i]=x[i]*y[i];
	// 	dft(x,len,-1);
	// 	poly tmp;
	// 	tmp.len=len;
	// 	for (int i=0;i<len;++i)
	// 		tmp.a[i]=(int)(x[i].r+0.5);
	// 	return tmp;
	// }
	void dwt(int opt)
	{
		for (int d=1;d<len;d*=2)
			for (int i=0;i<len;i+=d*2)
				for (int j=i;j<i+d;j++)
				{
					int x=a[j],y=a[j+d];
					if (opt==0) 
					{
						a[j]=(x+y)%mod;
						a[j+d]=(x-y+mod)%mod;
					}
					if (opt==1) 
						a[j]=(x+y)%mod;
					if (opt==2)
						a[j+d]=(x+y)%mod;
				}
	}
	void idwt(int opt)
	{
		for (int d=1;d<len;d*=2)
			for (int i=0;i<len;i+=d*2)
				for (int j=i;j<i+d;j++)
				{
					int x=a[j],y=a[j+d];
					if (opt==0) 
					{
						a[j]=(ll)(x+y)%mod*inv2%mod;
						a[j+d]=(ll)(x-y+mod)%mod*inv2%mod;
					}
					if (opt==1) 
						a[j]=(x+mod-y)%mod;
					if (opt==2)
						a[j+d]=(x+mod-y)%mod;
				}
	}
	poly fwt(const poly &b,const int &z)
	{
		poly x=*this,y=b;
		x.dwt(z);
		y.dwt(z);
		for (int i=0;i<len;++i)	
			x.a[i]=(ll)x.a[i]*y.a[i]%mod;
		x.idwt(z);
		return x;
	}
}a,c,d;
signed main()
{
	// puts("zhu");
	m=1<<17;
	// pre_work();
	inv2=ksm(2,mod-2);
	read(n);
	for (int i=1;i<=n;++i)
	{
		read(X);
		++a.a[X];
	}
	a.len=m;
	f[0]=0;
	f[1]=1;
	for (int i=2;i<m;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	for (int i=0;i<m;++i)
	{
		for (int j=i;;j=(j-1)&i)
		{
			g[i]+=a.a[j]*a.a[i^j];
			if (j==0) break;
		}
		g[i]%=mod;
	}
	for (int i=0;i<m;++i)
		c.a[i]=g[i]*f[i]%mod;
	c.len=m;
	d=a.fwt(a,0);
	for (int i=0;i<m;++i)
		d.a[i]=(ll)d.a[i]*f[i]%mod;
	for (int i=0;i<m;++i)
		a.a[i]=(ll)a.a[i]*f[i]%mod;
	a=a.fwt(c,1);
	a=a.fwt(d,1);
	for (int i=1;i<m;i*=2)
		(ans+=a.a[i])%=mod;
	cout<<ans;
	/*for (int i=1;i<=n;++i)
	{
		read(x);
		++a[x];
	}
	m=1<<17;
	for (int i=0;i<m;++i)
		b[i]=a[i];
	f[0]=0;
	f[1]=1;
	for (int i=2;i<m;++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	fwt(b,0);
	for (int i=0;i<m;++i)
		b[i]=(ll)b[i]*b[i]%mod;
	ifwt(b,0);*/

}