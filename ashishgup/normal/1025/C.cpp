#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
string s;

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	s+=s;
	for(int i=0;i<n;i++)
	{	
		int len=1;
		int j=i+1;
		while(j<2*n && s[i]!=s[j])
		{
			len++;
			i++, j++;
		}
		len=min(len, n);
		ans=max(ans, len);
	}
	cout<<ans;
	return 0;
}