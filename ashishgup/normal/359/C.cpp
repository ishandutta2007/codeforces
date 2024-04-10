#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, x, powsum=0;
int a[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		powsum+=a[i];
	}
	map<int, int> m;
	for(int i=1;i<=n;i++)
		m[powsum-a[i]]++;
	int carry=0, ans=0;
	for(auto &it:m)
	{
		carry=it.second/x;
		it.second%=x;
		if(it.second!=0)
		{
			ans=it.first;
			break;
		}
		if(carry>0)
			m[it.first+1]+=carry;
	}
	cout<<pow(x, min(ans, powsum), MOD);
	return 0;
}