#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, q, ans;
map<int, int> active;

void init()
{
	active[-1] = -1;
	active[2e9] = 2e9;
	active[1] = n;
}

void add(int L, int R)
{
	active[L]=R;
	ans+=R-L+1;
}

void remove(int L, int R)
{
	int removed=0;
	auto it = active.lower_bound(L);
	it--;
	if(it->second>=L)
	{
		active[L] = it->second;
		it->second = L-1;
	}
	it++;
	while(it->first <= R)
	{
		if(it->second > R)
		{
			removed+=R + 1 - it->first;
			active[R+1] = it->second;
		}
		else
			removed+= it->second - it->first + 1;
		auto it2=it;
		it++;
		active.erase(it2);
	}
	ans-=removed;
}

int32_t main()
{
	IOS;
	cin>>n>>q;
	init();
	ans=n;
	for(int i=1;i<=q;i++)
	{
		int l, r, k;
		cin>>l>>r>>k;
		remove(l, r);
		if(k==2)
			add(l, r);
		cout<<ans<<endl;
	}
	return 0;
}