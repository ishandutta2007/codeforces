#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;

int checkprime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

int get(int x)
{
	for(int i=x;;i--)
	{
		if(checkprime(i))
			return i;
	}
}

int get2(int x)
{
	for(int i=x+1;;i++)
	{
		if(checkprime(i))
			return i;
	}
}

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int largestP=get(n);
		int nextP=get2(n);
		int num=largestP-2;
		int den=2*largestP;
		int num2=n-largestP+1;
		int den2=largestP*nextP;
		int ans1=num*nextP + num2*2;
		int ans2=largestP*nextP*2;
		int store=__gcd(ans1, ans2);
		ans1/=store;
		ans2/=store;
		cout<<ans1<<"/"<<ans2<<endl;
	}
	return 0;
}