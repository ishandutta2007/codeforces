#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int md=1000000007;
const int N=100005;
vector<int> vct[N];
int m,i,j,k,x,y,z,ans,f[N],u[N],p[N],l;
bool v[N];
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&m);
	u[1]=1;
	for(i=2;i<=m;++i)
	{
		if(!v[i])
		{
			p[++l]=i;
			u[i]=md-1;
		}
		for(j=1;j<=l&&p[j]*i<=m;++j)
		{
			v[p[j]*i]=true;
			if(i%p[j]==0)
				break;
			else
				u[p[j]*i]=md-u[i];
		}
	}
	for(i=1;i<=m;++i)
		for(j=i;j<=m;j+=i)
			vct[j].push_back(i);
	f[1]=1;
	for(j=2;j<=m;++j)
	{
		f[j]=m;
		/*for(i=1;i<=m;++i)
			if(gcd(i,j)!=j)
			f[j]=(f[j]+f[gcd(i,j)])%md;*/
		for(y=vct[j].size()-1;y>=0;--y)
		if(vct[j][y]!=j)
		{
			i=vct[j][y];
			z=0;
			for(k=vct[j/i].size()-1;k>=0;--k)
			{
				x=vct[j/i][k];
				z=(z+1ll*u[x]*(m/i/x))%md;
			}
			f[j]=(f[j]+1ll*z*f[i])%md;
		}
		f[j]=1ll*pw(m-m/j,md-2)*f[j]%md;
	}
	for(i=1;i<=m;++i)
		ans=(ans+f[i])%md;
	ans=1ll*ans*pw(m,md-2)%md;
	printf("%d",ans);
	return 0;
}