#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]!='a')
		{
			while(i<n && s[i]!='a')
			{
				s[i]--;
				i++;
			}
			cout<<s;
			return 0;
		}	
	}
	s[n-1]='z';
	cout<<s;
}