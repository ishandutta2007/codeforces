#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, reqd;
map<int, int> b, s;

int32_t main()
{
	IOS;
	cin>>n>>reqd;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		int d, p;
		cin>>d>>p;
		if(ch=='B')
			b[d]+=p;
		else
			s[d]+=p;
	}
	vector<pair<int, int> > ans1, ans2;
	int cntr=0;
	for(auto it:s)
	{
		cntr++;
		ans1.push_back({it.first, it.second});
		if(cntr==reqd)
			break;
	}
	cntr=0;
	if(b.size())
	{
		for(auto it=--b.end();;it--)
		{
			cntr++;
			ans2.push_back({it->first, it->second});
			if(cntr==reqd || it==b.begin())
				break;
		}
	}
	sort(ans1.rbegin(), ans1.rend());
	sort(ans2.rbegin(), ans2.rend());
	for(auto it:ans1)
	{
		cout<<"S "<<it.first<<" "<<it.second<<endl;
	}
	for(auto it:ans2)
	{
		cout<<"B "<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}