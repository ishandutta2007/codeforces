#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int star=0, cnt=0;
int deg[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}	
	for(int i=1;i<=n;i++)
	{
		star|=(deg[i]==n-1);
		cnt+=(deg[i]==2);
	}
	if(star && m==n-1)
		cout<<"star topology";
	else if(cnt==n-2 && m==n-1)
		cout<<"bus topology";
	else if(cnt==n && m==n)
		cout<<"ring topology";
	else
		cout<<"unknown topology";
	return 0;
}