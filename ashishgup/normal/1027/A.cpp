#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		int i=0, j=n-1;
		bool check=1;
		for(;i<=j;i++, j--)
		{
			int diff=abs(s[i]-s[j]);
			if(diff==2 || diff==0)
				continue;
			check=0;
			break;
		}
		if(check)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}