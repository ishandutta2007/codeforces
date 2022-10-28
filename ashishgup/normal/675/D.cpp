#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
set<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	int num;
	cin>>num;
	s.insert(num);
	map<int, int> left, right;
	for(int i=2;i<=n;i++)
	{
		cin>>num;
		auto it=s.upper_bound(num);
		if(it==s.end())
		{
			it--;
			cout<<*it<<" ";
			right[*it]=num;
		}
		else 
		{
			if(left.find(*it)==left.end())
			{
				cout<<*it<<" ";
				left[*it]=num;
			}
			else
			{
				it--;
				cout<<*it<<" ";
				right[*it]=num;
			}
		}
		s.insert(num);
	}
	return 0;
}