#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int x, y;
vector<int> primedivs;

void precompute(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i)
			continue;
		while(x%i==0)
			x/=i;
		primedivs.push_back(i);
	}
	if(x>1)
		primedivs.push_back(x);
}

int f(int a, int b)
{
	if(b==0)
		return 0;
	if(b%a==0)
		return b/a;
	int cur=__gcd(a, b);
	int x=a/cur, y=b/cur, ans=1e15;
	for(auto &it:primedivs)
	{
		if(x%it==0)
			ans=min(ans, y%it);
	}
	return ans + f(a, b-cur*ans);
}

int32_t main()
{
	IOS;
	cin>>x>>y;
	precompute(x);
	cout<<f(x, y);
	return 0;
}