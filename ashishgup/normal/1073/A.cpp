#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i-1])
		{
			cout<<"YES"<<endl;
			cout<<s[i-1]<<s[i];
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}