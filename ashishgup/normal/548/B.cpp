#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=505;

int n, m, q;
int a[N][N], store[N][N], best[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j])
				store[i][j]=store[i][j-1] + 1;
			else
				store[i][j]=0;
			best[i]=max(best[i], store[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		s.insert(best[i]);
	while(q--)
	{
		int x, y;
		cin>>x>>y;
		a[x][y]^=1;
		s.erase(s.find(best[x]));
		best[x]=0;
		int i=x;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j])
				store[i][j]=store[i][j-1] + 1;
			else
				store[i][j]=0;
			best[i]=max(best[i], store[i][j]);
		}
		s.insert(best[i]);
		cout<<*(--s.end())<<endl;
	}
	return 0;
}