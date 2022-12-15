#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int power(int a,ll b)
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
vector<int> prime;
bool flag[100010];
void init()
{
	for(int i=2;i<=100000;i++)
	{
		if(!flag[i])prime.push_back(i);
		for(int j=0;j<prime.size()&&i*prime[j]<=100000;j++)
		{
			flag[i*prime[j]]=1;
			if((i%prime[j])==0)break;
		}
	}
}
int x;
ll n;
vector<int> fac;
int main()
{
	init();
	scanf("%d%lld",&x,&n);
	int tmp=x;
	for(int i=0;i<prime.size();i++)
	{
		if((tmp%prime[i])==0)
		{
			fac.push_back(prime[i]);
			while(tmp%prime[i]==0)tmp/=prime[i];
		}
	}
	if(tmp!=1)fac.push_back(tmp);
	int ret=1;
	for(int x:fac)
	{
		ll cur=1;
		while(cur<=n/x)
			cur*=x;
		ll tot=0;
		while(cur>=1)
		{
			ret=mult(ret,power(cur%mod,(n/cur)-tot));
			tot=n/cur;
			cur/=x;
		}
	}
	printf("%d\n",ret);
	return 0;
}