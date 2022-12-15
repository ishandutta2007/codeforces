#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n,m;
bool flag[100];
inline int calc(vector<int> v)
{
	memset(flag,0,sizeof(flag));
	for(auto &x:v)flag[x]=1;
	int ret=0;
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(v[i]+v[j]<100&&flag[v[i]+v[j]])ret++;
		}
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;i+j<=n;j++)cnt++;
	}
	if(cnt<m)
	{
		puts("-1");
		return 0;
	}
	if(!m)
	{
		for(int i=n;i<2*n;i++)printf("%d ",i);
		return 0;
	}
	if(cnt==m)
	{
		for(int i=1;i<=n;i++)printf("%d ",i);
		return 0;
	}
	int l=1;
	while(1)
	{
		if(cnt-(n-l-1)+(n-l-1)/2<m)
		{
			int r=l+n-1;
			while(cnt>m)
			{
				for(int i=l;i<l+n-1;i++)cnt-=(r-i<l+n-1&&r-i>i);
				++r;
				for(int i=l;i<l+n-1;i++)cnt+=(r-i<l+n-1&&r-i>i);
				if(cnt==m)break;
			}
			for(int i=0;i<n-1;i++)printf("%d ",l+i);
			printf("%d ",r);
			return 0;
		}
		cnt=cnt-(n-l-1)+(n-l-1)/2;
		l++;
	}
	return 0;
}