#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e6+3;

int n, k;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b>0)
	{
		if(b%2)
		{
			ans*=a;
			ans%=m;
		}
		a*=a;
		a%=m;
		b/=2;
	}
	return ans;
}

int modinv(int x, int m)
{
	return pow(x, m-2, m);
}

int max2(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=x/2;
		x/=2;
	}
	return ans;
}

int calc(int x)
{
	if(k>=MOD)
		return 0;
	x%=MOD;
	int ans=1;
	for(int i=1;i<=k-1;i++)
	{
		int cur=x-i;
		if(cur<0)
			cur+=MOD;
		ans*=cur;
		ans%=MOD;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	if(n<=60) //Pigeonhole Principle
	{
		if(k>(1LL<<n))
		{
			cout<<"1 1";
			return 0;
		}
	}
	int powden=((k-1)%(MOD-1)) * ((n)%(MOD-1));
	powden%=(MOD-1);
	int find2=max2(k-1);
	int den=pow(2LL, powden, MOD) * modinv(pow(2LL, find2, MOD), MOD);
	den%=MOD;
	int num=den;
	int to_subtract_num=modinv(pow(2LL, find2, MOD), MOD);
	to_subtract_num*=calc(pow(2LL, n, MOD));
	to_subtract_num%=MOD;
	num-=to_subtract_num;
	num+=MOD;
	num%=MOD;
	cout<<num<<" "<<den;
	return 0;
}