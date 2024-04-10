#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k;
int level[N];
vector<pair<int, int> > ans;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		int u=max(1LL, i-k);
		level[i]=level[u]+1;
		ans.push_back({u, i});
	}
	cout<<level[n]+level[n-1]<<endl;
	for(auto &it:ans)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}