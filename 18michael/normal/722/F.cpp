#include<cstdio>
#include<vector>
#define Mx 16
#define LL long long
using namespace std;
int n,m,ans;
int k[100002];
vector<int> vec[100002];
typedef pair<int,int> P;
vector<P> vec1[100002];
struct aaa
{
	LL a,b;
}f[100002][17],tmp,tmp1;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
inline LL Pow(LL a,LL b,LL mod)
{
	if(!b)return 1;
	if(b==1)return (a%mod);
	LL c=Pow(a,(b>>1),mod);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline LL fai(LL x)
{
	LL t=x;
	for(LL i=2;i*i<=x;++i)
		if(!(x%i))
		{
			t=t/i*(i-1);
			do x/=i;while(!(x%i));
		}
	if(x>1)t=t/x*(x-1);
	return t;
}
inline aaa merge(aaa x,aaa y)
{
	LL t=x.b/gcd(x.b,y.b)*y.b,t1=(y.a-x.a+t)%t,t2=gcd(t1,x.b);
	x.b/=t2,t1/=t2,y.b/=gcd(y.b,t2);if(gcd(x.b,y.b)>1)return (aaa){0,0};
	return (aaa){(((t1*Pow(x.b,fai(y.b)-1,y.b))%y.b)*((x.b*t2)%t)+x.a)%t,t};
}
inline void solve(int x,int l,int r)
{
	for(int i=l;i<=r;++i)f[i][0]=(aaa){vec1[x][i].second,k[vec1[x][i].first]};
	for(int i=1;i<=Mx;++i)
		for(int j=l;j+(1<<i)-1<=r;++j)
		{
			if(f[j][i-1].b && f[j+(1<<(i-1))][i-1].b)f[j][i]=merge(f[j][i-1],f[j+(1<<(i-1))][i-1]);
			else f[j][i]=(aaa){0,0};
		}
	for(int i=l,t;i<=r;++i)
	{
		t=i,tmp=(aaa){0,1};
		for(int j=Mx;~j;--j)
			if(t+(1<<j)-1<=r && f[t][j].b && (tmp1=merge(tmp,f[t][j])).b)
				t+=(1<<j),tmp=tmp1;
		ans=max(ans,t-i);
	}
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)
	{
		read(k[i]);
		for(int j=0,x;j<k[i];++j)read(x),vec[i].push_back(x),vec1[x].push_back(P(i,j));
	}
	for(int i=1;i<=m;++i)
	{
		ans=0;
		for(int j=0,l,v;j<vec1[i].size();j=l)
		{
			for(l=j+1;j<vec1[i].size();++l)
				if(vec1[i][l].first!=vec1[i][l-1].first+1)
					break;
			solve(i,j,l-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}