#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=55;

int n, p, ans;
string s[N];

int32_t main()
{
	IOS;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	int cur=0;
	for(int i=n;i>=1;i--)
	{
		if(s[i].size()==8)
			ans+=cur*p + p/2, cur=cur*2+1;
		else
			ans+=cur*p, cur*=2;
	}	
	cout<<ans;
	return 0;
}