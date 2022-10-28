#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n, s, cnt=0;
int deg[N];

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}	
	for(int i=1;i<=n;i++)
		cnt+=(deg[i]==1);
	double ans=2.0l*s/cnt;
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}