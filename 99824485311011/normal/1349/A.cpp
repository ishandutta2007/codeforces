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
int n,a[200010];
inline int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
vector<int> v[200010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=2;j*j<=t;j++)
		{
			if(a[i]%j==0)
			{
				int cur=1;
				while(a[i]%j==0)a[i]/=j,cur*=j;
				v[j].push_back(cur);
			}
		}
		if(a[i]!=1)v[a[i]].push_back(a[i]);
	}
	long long g=1;
	for(int i=2;i<=200000;i++)
	{
		if(v[i].size()==n)
		{
			sort(v[i].begin(),v[i].end());
			g*=v[i][1];
		}
		else if(v[i].size()==n-1)
		{
			sort(v[i].begin(),v[i].end());
			g*=v[i][0];
		}
	}
	printf("%lld\n",g);
	return 0;
}