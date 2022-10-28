#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;

int next(int k)
{
	return k*10 + 9;
}

int sum(int k)
{
	int cur=0;
	while(k>0)
	{
		cur+=k%10;
		k/=10;
	}
	return cur;
}

int32_t main()
{
	IOS;
	cin>>n;
	int cur=0;
	while(next(cur)<=n)
		cur=next(cur);
	int a=cur;
	int b=n-cur;
	int ans=sum(a) + sum(b);
	cout<<ans;
	return 0;
}