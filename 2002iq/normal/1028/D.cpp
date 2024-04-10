#include <iostream>
#include <set>
using namespace std;
#define mod 1000000007
set<int> occ;
set<pair<int,int> > st;
int pre(int x)
{
	return *prev(occ.lower_bound(x));
}
int arr(int x)
{
	auto p=*st.upper_bound({x,-1});
	if (p.first!=x)
	return 0;
	return p.second;
}
int main()
{
	int q;
	cin >> q;
	st.insert({0,1});
	occ.insert(0);
	while (q--)
	{
		string s;
		int x;
		cin >> s >> x;
		if (s=="ADD")
		{
			occ.insert(x);
			st.insert({x,arr(pre(x))});
		}
		else
		{
			occ.erase(x);
			int tmp=arr(pre(x))+arr(x);
			st.clear();
			st.insert({pre(x),tmp%mod});
			if (pre(x))
			st.insert({0,0});
		}
	}
	int ans=0;
	for (auto p:st)
	ans=(ans+p.second)%mod;
	cout << ans;
}