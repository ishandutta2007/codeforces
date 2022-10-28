#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N][5];
bool vis[N];

bool check2(int i, int j)
{
	if(a[i][0]!=j && a[i][1]!=j)
		return false;
	return true;
}

void check(int idx)
{
	memset(vis, 0, sizeof(vis));
	vector<int> v;
	v.push_back(1);
	v.push_back(a[1][idx]);
	v.push_back(a[1][idx^1]);
	vis[1]=1;
	vis[a[1][idx]]=1;
	vis[a[1][idx^1]]=1;
	int cur=1;
	while(cur<v.size())
	{
		int node=v[cur++];
		if(!vis[a[node][0]])
		{
			vis[a[node][0]]=1;
			v.push_back(a[node][0]);
		}
		else if(!vis[a[node][1]])
		{
			vis[a[node][1]]=1;
			v.push_back(a[node][1]);
		}
		else 
			break;
	}
	if(v.size()!=n)
		return;
	v.push_back(v[0]);
	v.push_back(v[1]);
	for(int i=0;i<n;i++)
	{
		if(!check2(v[i], v[i+1]) || !check2(v[i], v[i+2]))
			return;
	}
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
			cin>>a[i][j];
	check(0);
	check(1);
	return 0;
}