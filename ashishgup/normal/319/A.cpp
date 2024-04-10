#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n;
string s;

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

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			int cur=pow(2LL, i, MOD) * pow(4LL, n-1-i, MOD);
			cur%=MOD;
			ans+=cur;
		}
	}
	ans%=MOD;
	cout<<ans;
	return 0;
}