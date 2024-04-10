#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5;
const int MOD=1e9+7;

int n, ans=1, check=1, maxB=0, leastS;
multiset<int> s;

void init()
{
	maxB=0;
	leastS=308983067;
}

int32_t main()
{
	IOS;
	init();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string op;
		cin>>op;
		if(op=="ADD")
		{
			int cur;
			cin>>cur;
			s.insert(cur);
			if(i==n)
			{
				int curans=1;
				auto it=s.lower_bound(maxB+1);
				while(it!=s.end() && *it<leastS)
				{
					curans++;
					it++;
				}
				ans*=curans;
				ans%=MOD;
			}
		}
		else 
		{
			int cur;
			cin>>cur;
			if(cur<maxB)
			{
				cout<<"0";
				return 0;
			}
			if(cur>leastS)
			{
				cout<<"0";
				return 0;
			}
			if(cur!=leastS && cur!=maxB)
				ans*=2;
			ans%=MOD;
			s.erase(cur);
			auto it=s.lower_bound(cur);
			if(it!=s.end())
				leastS=*it;
			else
				leastS=308983067;
			if(it!=s.begin())
				maxB=*(--it);
			else
				maxB=0;
		}
	}
	cout<<ans;
	return 0;
}