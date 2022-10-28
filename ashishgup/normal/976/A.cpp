#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	string s;
	cin>>s;
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	for(int i=0;i<n;i++)
	{
		if(i<n && s[i+1]=='1')
			continue;
		cout<<s[i];
	}
	return 0;
}