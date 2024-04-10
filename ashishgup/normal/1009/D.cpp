#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
vector<int> g[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	if(m<n-1)
	{
		cout<<"Impossible";
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		m--;
		g[i].push_back(i+1);
	}
	for(int i=1;i<=n&&m;i++)
	{
		for(int j=i+2;j<=n&&m;j++)
		{
			if(__gcd(i, j)==1)
			{
				g[i].push_back(j);
				m--;
			}
		}
	}
	if(m)
		cout<<"Impossible";
	else
	{
		cout<<"Possible"<<endl;
		for(int i=1;i<=n;i++)
			for(auto it:g[i])
				cout<<i<<" "<<it<<endl;
	}
	return 0;
}