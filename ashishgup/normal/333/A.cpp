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
	int storen=n;
	vector<int> v;
	while(storen>0)
	{
		v.push_back(storen%3);
		storen/=3;
	}
	int cur=1;
	for(int i=0;i<v.size();i++)
	{
		cur*=3;
		if(v[i]!=0)
			break;
	}
	int ans=n/cur + (n%cur?1:0);
	cout<<ans;
	return 0;
}