#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n;
map<string, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(!m[s])
			cout<<"OK"<<endl;
		else
			cout<<s<<m[s]<<endl;
		m[s]++;
	}
	return 0;
}