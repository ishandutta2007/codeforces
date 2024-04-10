#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<char> ans;
	ans.push_back('+');
	int cur=a[n];
	for(int i=n-1;i>=1;i--)
	{
		if(cur>0)
		{
			cur-=a[i];
			ans.push_back('-');
		}
		else
		{
			cur+=a[i];
			ans.push_back('+');
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto it:ans)
	{
		if(cur>=0)
			cout<<it;
		else
			cout<<((it=='+')?'-':'+');
	}
	return 0;
}