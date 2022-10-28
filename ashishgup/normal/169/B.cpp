#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string a, b;
	cin>>a>>b;
	sort(b.begin(), b.end());
	for(auto &it:a)
	{
		if(!b.size())
			break;
		if(b.back()>it)
		{
			it=b.back();
			b.pop_back();
		}
	}
	cout<<a;
	return 0;
}