#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

long double a[N];

int32_t main()
{
	IOS;
	int n, p, q;
	cin>>p>>q>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int num=p, den=q;
	for(int i=1;i<=n;i++)
	{
		long double lhs=(long double)num/den;
		long double rhs=a[i];
		if(rhs>lhs)
		{
			cout<<"NO";
			return 0;
		}
		num=num-a[i]*den;
		if(i<=n-1)
			swap(num, den);
		if(den==0)
		{
			cout<<"NO";
			return 0;
		}
	}
	if(num==0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}