#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int rem[N], c[N];
multiset<pair<int, int> > s;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>rem[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		s.insert({c[i], i});
	}
	for(int i=1;i<=m;i++)
	{
		int dish, num;
		cin>>dish>>num;
		int take=min(num, rem[dish]);
		rem[dish]-=take;
		num-=take;
		int curcost=c[dish] * take;
		while(num>0 && s.size())
		{
			pair<int, int> p=*s.begin();
			s.erase(p);
			int have=rem[p.second];
			take=min(have, num);
			curcost+=take*c[p.second];
			num-=take;
			rem[p.second]-=take;
			if(rem[p.second]>0)
				s.insert(p);
		}
		if(num>0)
			curcost=0;
		cout<<curcost<<endl;
	}
	return 0;
}