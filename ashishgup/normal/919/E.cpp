#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int a, b, p, x;

int pow(int p, int q, int m)
{
	int ans=1;
	while(q>0)
	{
		if(q%2)
		{
			ans*=p;
			ans%=m;
		}
		p*=p;
		p%=m;
		q/=2;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, p-2, p);
}

int32_t main()
{
	IOS;
	cin>>a>>b>>p>>x;
	int ans=0;
	int cur=1;
	for(int i=0;i<=p-2;i++)
	{
		int reqd=modinv(cur);
		reqd*=b;
		reqd%=p;
		int diff=(i-reqd);
		if(diff<0)
			diff+=(p-1);
		reqd+=p*diff;
		if(reqd<=x)
		{
			ans+=(x-reqd+p*(p-1))/(p*(p-1));
		}
		cur*=a;
		cur%=p;
	}
	cout<<ans;
	return 0;
}