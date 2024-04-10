#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, b;
vector<pair<int, int> > divs;

void work()
{
	for(int i=2;i*i<=b;i++)
	{
		if(b%i)
			continue;
		int ct=0;
		while(b%i==0)
		{
			ct++;
			b/=i;
		}
		divs.push_back({i, ct});
	}
	if(b>1)
		divs.push_back({b, 1});
}

int32_t main()
{
	IOS;
	cin>>n>>b;
	work();
	int ans=1e18;
	for(auto &it:divs)
	{
		int curn=n;
		int p=it.first;
		int curans=0;
		while(p<=curn)
		{
			curans+=curn/p;
			if(p<=curn/it.first)
				p*=it.first;
			else
				break;
		}
		curans=curans/it.second;
		ans=min(ans, curans);
	}
	cout<<ans;
	return 0;
}