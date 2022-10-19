#include <iostream>
#include <map>
using namespace std;

int a[3003],c[303];
long long n,m,k,minu,t;
map<long long,long long> dp;
map<long long,long long> cpd;
map<long long,long long>::iterator it;
long long gcd(long long a,long long b)
{
	if(a==0 || b==0)
		return a+b;
	if(b>a)
		return gcd(a,b%a);
	if(b<a)
		return gcd(a%b,b);
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>c[i];
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		for(it=dp.begin();it!=dp.end();++it)
		{
			t=gcd(it->first,a[i]);
			if(dp.find(t)!=dp.end())
				dp[t]=min(dp[it->first]+c[i],dp[t]);
			else
				dp[t]=dp[it->first]+c[i];
		}
	}
	if(dp[1]==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<dp[1]<<endl;
	return 0;
}