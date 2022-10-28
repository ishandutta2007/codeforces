#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e6+5;

int n;
double ans=0;
int a[N];
vector<int> g[N];

int get(int n)
{
	if(n<1)
		return 0;
	int ans=n*(n+1)/2;
	ans*=2;
	ans-=n;
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]].push_back(i);
	}	
	for(int i=1;i<=1e6;i++)
	{
		if(!g[i].size())
			continue;
		int tot=n*n;
		int curl=1, curr=1;
		for(auto &it:g[i])
		{
			int curr=it-1;
			tot-=get(curr-curl+1);
			curl=it+1;
		}
		curr=n;
		tot-=get(curr-curl+1);
		ans+=1.0l*tot/(n*n);
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}