// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

LL mult(LL x,LL y,LL mod)
{
	LL tmp=x*y-LL((long double)1.0*x/mod*y+1e-8)*mod;
	while(tmp<0)tmp+=mod;
	while(tmp>=mod)tmp-=mod;
	return tmp;/**/
}
namespace factor
{
	LL power(LL x,LL y,LL mod)
	{
		LL ret=1;x%=mod;
		do
		{
			if(y&1)ret=mult(ret,x,mod);
			x=mult(x,x,mod);
		}while(y>>=1);
		return ret;
	}
	bool MillerRabin(LL n,int a)
	{
		LL d=n-1;int s=0;
		while(~d&1)
		{
			s++;
			d>>=1;
		}
		LL p=power(a,d,n);
		if(p==1)return true;
		for(int i=0;i<s;i++)
		{
			if(p==n-1)return true;
			p=mult(p,p,n);
		}
		return false;
	}
	bool isprime(LL n)
	{
		for(int i=2;i<30&&i<n;i++)if(!MillerRabin(n,i))return false;
		return true;
	}
	void rho(LL n,vector<LL>&ret)
	{
		if(n==1)return;
		if(isprime(n))
		{
			ret.pb(n);
			return;
		}
		if(n==4)
		{
			ret.pb(2);
			ret.pb(2);
			return;
		}
		while(true)
		{
			LL x=2,y=2,d=1;int k=rand()+1;
			while(d==1)
			{
				x=(mult(x,x,n)+k)%n;
				y=(mult(y,y,n)+k)%n;
				y=(mult(y,y,n)+k)%n;
				d=__gcd(n,abs(x-y));
			}
			if(d!=n)
			{
				rho(d,ret);rho(n/d,ret);
				break;
			}
		}
	}
};

void ext_gcd(LL m,LL n,LL&a,LL&b)
{
	if(n==0)
	{
		a=1;b=0;
		return;
	}
	LL aa,bb;
	ext_gcd(n,m%n,aa,bb);
	a=bb;b=aa-bb*(m/n);
}

struct solver
{
	int tp;
	LL k1,k2,a,b,dist[100111];
	void go(LL k)
	{
		vector<LL>f;factor::rho(k,f);
		sort(f.begin(),f.end());f.erase(unique(f.begin(),f.end()),f.end());
//		printf("k= %lld\n",k);
//		for(auto v:f)printf("%lld ",v);puts("");
		if((int)f.size()==0)tp=-1;
		else if((int)f.size()==1)
		{
			tp=0;
			k1=f[0];
		}
		else if((int)f.size()==2)
		{
			tp=1;
			k1=f[0];k2=f[1];
			ext_gcd(k1,k2,a,b);
			a=(a%k2+k2)%k2;
		}
		else
		{
			tp=2;
			k1=f[0];
			priority_queue<pair<LL,int> >q;
			for(int i=1;i<k1;i++)dist[i]=Linf;dist[0]=0;
			q.push(mp(0,0));
			while(!q.empty())
			{
				int x=q.top().ss;LL d=-q.top().ff;q.pop();
				if(dist[x]!=d)continue;
				for(int j=1;j<(int)f.size();j++)
				{
					int v=(x+f[j])%k1;
					if(dist[v]>dist[x]+f[j])
					{
						dist[v]=dist[x]+f[j];
						q.push(mp(-dist[v],v));
					}
				}
			}
		}
	}
	bool check(LL x)
	{
		if(tp==-1)return false;
		else if(tp==0)return (x%k1==0);
		else if(tp==1)return x/k1>=mult(a,x,k2);
		else return (dist[x%k1]<=x);
	}
};
solver a[55];
int tot;
map<LL,int> id;

LL n,k;
void solve()
{
	get2(n,k);
	if(!id[k])
	{
		id[k]=++tot;
		a[tot].go(k);
	}
	puts(a[id[k]].check(n)?"YES":"NO");
}
int main()
{
	int tc;get1(tc);while(tc--)solve();
	return 0;
}