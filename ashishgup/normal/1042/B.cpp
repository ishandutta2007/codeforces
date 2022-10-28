#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
map<string, int> m;
vector<pair<string, int> > v;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int price;
		cin>>price;
		string s;
		cin>>s;
		sort(s.begin(), s.end());
		if(m.find(s)!=m.end())
			m[s]=min(m[s], price);
		else
			m[s]=price;
	}
	int ans=1e9;
	for(auto &it:m)
		v.push_back(it);
	n=v.size();
	for(int i=0;i<(1<<n);i++)
	{
		bool cA=0, cB=0, cC=0;
		int price=0;
		for(int j=0;j<n;j++)
		{
			if(i>>j & 1)
			{
				for(auto k:v[j].first)
				{
					cA|=(k=='A');
					cB|=(k=='B');
					cC|=(k=='C');
				}
				price+=v[j].second;
			}
		}
		if(cA && cB && cC)
			ans=min(ans, price);
	}
	if(ans==1e9)
		ans=-1;
	cout<<ans;
	return 0;
}