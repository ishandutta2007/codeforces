#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

vector<string> ans;

int32_t main()
{
	IOS;
	int h1, a1, c1, h2, a2;
	cin>>h1>>a1>>c1>>h2>>a2;
	while(h2>0)
	{
		if(h2-a1<=0)
		{
			ans.push_back("STRIKE");
			h2-=a1;
			break;
		}
		if(h1-a2<=0)
		{
			h1+=c1;
			h1-=a2;
			ans.push_back("HEAL");
		}
		else
		{
			ans.push_back("STRIKE");
			h2-=a1;
			h1-=a2;
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
	{
		cout<<it<<endl;
	}
	return 0;
}