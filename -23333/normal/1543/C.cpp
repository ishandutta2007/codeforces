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
const int mo=1e9+7;
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
const double eps=1e-6;
double dfs(double a,double b,double c,double k,int now,double p)
{
//	cerr<<a<<" "<<b<<" "<<c<<endl;
	double ans=p*c*(now+1);
	double a1=a,b1=b,c1=c;
	if (a>eps)
	{
		double tt=min(a,k);
		a-=tt;
		if (b>eps)
		{
			b+=tt/2; c+=tt/2;
		} else c+=tt;
		ans+=dfs(a,b,c,k,now+1,p*a1);
	}
	a=a1,b=b1,c=c1;
	if (b>eps)
	{
		double tt=min(b,k);
		b-=tt;
		if (a>eps)
		{
			a+=tt/2; c+=tt/2;
		} else c+=tt;
		ans+=dfs(a,b,c,k,now+1,p*b1);
	}
	return ans;
}
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	double a,b,c,k;
   	cin>>a>>b>>c>>k;
   	double ans=dfs(a,b,c,k,0,1);
   	printf("%.10lf\n",ans);
   }
   return 0;
}