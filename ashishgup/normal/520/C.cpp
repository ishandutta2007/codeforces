#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n;
string s;
map<char, int> m;

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
	cin>>n>>s;
	for(auto &it:s)
		m[it]++;
	int maxf=0, ct=0;
	for(auto &it:m)
	{
		if(it.second>maxf)
		{
			maxf=it.second;
			ct=1;
		}
		else if(it.second==maxf)
			ct++;
	}
	cout<<pow(ct, n, MOD);
	return 0;
}