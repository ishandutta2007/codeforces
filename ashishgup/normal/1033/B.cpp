#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int isprime(int k)
{
	for(int i=2;i*i<=k;i++)
	{
		if(k%i==0)
			return 0;
	}
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin>>a>>b;
		if(a!=b+1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(isprime(a+b))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}