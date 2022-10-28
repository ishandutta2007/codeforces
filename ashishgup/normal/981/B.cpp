#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int a[N], b[N], x[N], y[N];
map<int, int> ans;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
		ans[a[i]]=x[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i]>>y[i];
		ans[b[i]]=max(ans[b[i]], y[i]);
	}
	int answer=0;
	for(auto it:ans)
		answer+=it.second;
	cout<<answer;
	return 0;
}