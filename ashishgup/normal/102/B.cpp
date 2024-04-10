#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=1;
string s;

int sum(int x)
{
	int cur=0;
	while(x>0)
	{
		cur+=x%10;
		x/=10;
	}
	return cur;
}

int32_t main()
{
	IOS;
	cin>>s;
	if(s.size()==1)
	{
		cout<<"0";
		return 0;
	}
	for(auto &it:s)
		n+=(it-'0');
	while(n>9)
	{
		ans++;
		n=sum(n);
	}
	cout<<ans;
	return 0;
}