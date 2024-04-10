#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];
set<pair<int, int> > l, r;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r.insert({a[i], i});
	}
	for(int i=1;i<=n;i++)
	{
		r.erase({a[i], i});
		bool check=1;
		if(l.size() && r.size())
		{
			auto left=l.rbegin();
			auto right=r.rbegin();
			if(left->first>a[i] && right->first>a[i])
			{
				cout<<3<<endl;
				cout<<left->second<<" "<<i<<" "<<right->second;
				return 0;
			}
			auto left2=l.begin();
			auto right2=r.begin();
			if(left2->first<a[i] && right2->first<a[i])
			{
				cout<<3<<endl;
				cout<<left2->second<<" "<<i<<" "<<right2->second;
				return 0;
			}
		}
		l.insert({a[i],i });
	}
	cout<<"0";
	return 0;
}