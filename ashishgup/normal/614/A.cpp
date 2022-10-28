#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int l, r, k;
	cin>>l>>r>>k;
	int cur=1;
	vector<int> v;
	while(true)
	{
		if(cur>=l)
			v.push_back(cur);
		if(cur<=r/k)
			cur*=k;
		else
			break;
	}
	if(!v.size())
		v.push_back(-1);
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}