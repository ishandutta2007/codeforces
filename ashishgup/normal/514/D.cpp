#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int M=6;

int n, m, k, ans=0;
int a[N][M], store[N];
multiset<int> s[N];

void add(int idx)
{
	for(int i=1;i<=m;i++)
		s[i].insert(a[idx][i]);
}

void remove(int idx)
{
	for(int i=1;i<=m;i++)
		s[i].erase(s[i].find(a[idx][i]));
}

int reqd()
{
	if(!s[1].size())
		return 0;
	int ans=0;
	for(int i=1;i<=m;i++)
		ans+=*(--s[i].end());
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	int l=1;
	for(int r=1;r<=n;r++)
	{
		add(r);
		while(reqd()>k)
			remove(l++);
		if(r-l+1>ans)
		{
			ans=r-l+1;
			for(int i=1;i<=m;i++)
				store[i]=*(--s[i].end());
		}
	}
	for(int i=1;i<=m;i++)
		cout<<store[i]<<" ";
	return 0;
}