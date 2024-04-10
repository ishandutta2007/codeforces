#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,t;
LL ans=1,M,res;
int a[102],b[102],k[102];
int c[3002][102],d[3002][102];
unordered_set<int> s;
unordered_set<int>::iterator it;
vector<int> vec,vec1,vec2;
inline void ins(int x)
{
	for(int i=2;i*i<=x;++i)if(!(x%i))for(s.insert(i);!(x%i);x/=i);
	if(x>1)s.insert(x);
}
inline LL Pow(int a,LL b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline int calc(int x,int y)
{
	return x%y? -1:x/y;
}
inline void solve(int x,int y)
{
	for(int i=1;i<=n;++i)
		for(int j=0;j<vec.size();++j)
			if(d[j][i])
			{
				if((k[i]=calc(c[j][x]+d[j][x]*y-c[j][i],d[j][i]))<0)return (void)(puts("-1"));
				break;
			}
	for(int i=1;i<vec.size();++i)for(int j=2;j<=n;++j)if(c[i][j]+d[i][j]*k[j]!=c[i][1]+d[i][1]*k[1])return (void)(puts("-1"));
	for(int i=0;i<vec.size();++i)(ans*=Pow(vec[i],c[i][1]+d[i][1]*k[1]))%=mod;
	printf("%lld",ans);
}
inline bool cmp(int Ax,int Ay,int Bx,int By)
{
	return Ax*By==Bx*Ay;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]),ins(a[i]),ins(b[i]);
	if(n==1)return 0&printf("%d",a[1]);
	for(it=s.begin();it!=s.end();vec.push_back(*it),++it)
		for(int i=1,j;i<=n;++i)
		{
			for(j=a[i];!(j%(*it));j/=*it)++c[vec.size()][i];
			for(j=b[i];!(j%(*it));j/=*it)++d[vec.size()][i];
		}
	for(int i=0;i<vec.size();++i)
	{
		vec1.push_back(i),t=0;
		for(int j=1;j<=n;++j)
			if(!d[i][j] && d[i][(j%n)+1])
			{
				t=j;
				break;
			}
		if(t)
		{
			if((c[i][t]-c[i][(t%n)+1])%d[i][(t%n)+1])return 0&puts("-1");
			return solve((t%n)+1,(c[i][t]-c[i][(t%n)+1])/d[i][(t%n)+1]),0;
		}
		if(d[i][1])continue;
		for(int j=1;j<n;++j)if(c[i][j]!=c[i][j+1])return 0&puts("-1");
		(ans*=Pow(vec[i],c[i][1]))%=mod,vec1.pop_back();
	}
	vec2=vec,vec.clear();
	for(int i=0;i<vec1.size();++i)
	{
		vec.push_back(vec2[vec1[i]]);
		for(int j=1;j<=n;++j)c[i][j]=c[vec1[i]][j],d[i][j]=d[vec1[i]][j];
	}
	for(int i=1,x;i<n;++i)
		for(int j=1;j<vec.size();++j)
		{
			if(cmp(d[0][i],d[j][i],d[0][i+1],d[j][i+1]))
			{
				if(!cmp(d[0][i],d[j][i],c[0][i+1]-c[0][i],c[j][i+1]-c[j][i]))return 0&puts("-1");
				continue;
			}
			if((x=calc((c[0][i+1]-c[0][i])*d[j][i]-(c[j][i+1]-c[j][i])*d[0][i],(d[0][i]*d[j][i+1]-d[0][i+1]*d[j][i])))<0)return 0&puts("-1");
			return solve(i+1,x),0;
		}
	for(int i=0;i<vec.size();++i)
	{
		M=1,res=0;
		for(int j=1;j<=n;++j)
		{
			for(int k=0;k<d[i][j] && (res-c[i][j])%d[i][j];++k)res+=M;
			if((res-c[i][j])%d[i][j])return 0&puts("-1");
			M=M*d[i][j]/__gcd(M,(LL)d[i][j]);
		}
		for(int j=1;j<=n;++j)for(;res<c[i][j];res+=M);
		(ans*=Pow(vec[i],res))%=mod;
	}
	return 0&printf("%lld",ans);
}