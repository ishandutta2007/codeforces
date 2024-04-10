#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ans=0;
int a[N];
set<pair<int, int> > s, rem;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int l=1;l<=n;l++)
	{
		int r=l;
		while(r+1<=n && a[r+1]==a[l])
			r++;
		s.insert({l, r-l+1});
		rem.insert({-(r-l+1), l});
		l=r;
	}
	while(rem.size())
	{		
		ans++;
		auto it=*rem.begin();
		int idx=it.second;
		rem.erase(it);
		auto it2=s.lower_bound(make_pair(idx, 0));
		auto L=it2, R=it2;
		if(L!=s.begin() && R!=s.end())
		{
			L--;
			R++;
			if(R!=s.end())
			{
				if(a[L->first]==a[R->first])
				{
					rem.erase({-L->second, L->first});
					rem.erase({-R->second, R->first});
					pair<int, int> cur={L->first, L->second + R->second};
					s.erase(L);
					s.erase(R);
					s.insert(cur);
					rem.insert({-cur.second, cur.first});
				}
			}
		}
		s.erase(it2);
	}
	cout<<ans;
	return 0;
}