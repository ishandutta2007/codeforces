#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
int a[N], b[N], c[N];
map<int, int> store;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		store[a[i]]++;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	int ans=1;
	int p=0, q=0;
	for(int i=1;i<=m;i++)
	{
		if(store[b[i]]>p)
		{
			ans=i;
			p=store[b[i]];
			q=store[c[i]];
		}
		else if(store[b[i]]==p && store[c[i]]>q)
		{
			ans=i;
			p=store[b[i]];
			q=store[c[i]];
		}
	}
	cout<<ans;
	return 0;
}