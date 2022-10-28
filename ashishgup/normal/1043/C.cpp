#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n;
int ans[N];
string s;

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(int i=0;i<n-1;i++)
	{
		if(s[i+1]!=s[i])
		{
			ans[i]=1;
			reverse(s.begin(), s.begin()+i+1);
		}
	}
	if(s.back()=='a')
	{
		reverse(s.begin(), s.end());
		ans[n-1]=1;
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;
}