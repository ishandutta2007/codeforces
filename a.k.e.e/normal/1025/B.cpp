#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN=50005;

int n;

ll gcd(ll a,ll b)
	{return b?gcd(b,a%b):a;}

int main()
{
	cin>>n;
	ll ans=0;
	int a,b;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		ans=gcd(ans,(ll)b*a);
	}
	if(ans==1)return 0*printf("-1\n");
	for(int i=2;i*i<=a;i++)
		if(!(a%i))
		{
			while(!(a%i))a/=i;
			if(!(ans%i))return 0*printf("%d\n",i);
		}
	if(!(ans%a))return 0*printf("%d\n",a);
	a=b;
	for(int i=2;i*i<=a;i++)
		if(!(a%i))
		{
			while(!(a%i))a/=i;
			if(!(ans%i))return 0*printf("%d\n",i);
		}
	if(!(ans%a))return 0*printf("%d\n",a);
	return 0;
}