#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	int ct=0;
	for(auto it:m)
		ct+=(it.second>=2);
	int l=1, r=1;
	set<int> s;
	vector<pair<int, int> > ans;
	while(ct>=1 && r<=n)
	{
		s.clear();
		while(r<=n && s.find(a[r])==s.end())
		{
			s.insert(a[r]);
			m[a[r]]--;
			ct-=(m[a[r]]==1);
			r++;
		}
		m[a[r]]--;
		ct-=(m[a[r]]==1);
		if(ct>=1 && r<=n)
		{
			ans.push_back({l, r});
			l=r+1;
		}
		else if(r<=n)
		{
			r=n;
			ans.push_back({l, r});
		}
		r++;
	}
	if(!ans.size())
		cout<<"-1";
	else
	{
		cout<<ans.size()<<endl;
		for(auto it:ans)
			cout<<it.first<<" "<<it.second<<endl;
	}

	return 0;
}