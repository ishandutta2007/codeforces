#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;
const int LG=11;

int n, curck;
int a[N], par[LG][N], cache[N][1<<8]; 
vector<int> g[N];
set<int> s;

void precompute()
{
	for(int i=1;i<LG;i++)
	{
		for(int j=1;j<=n;j++)
		{
			par[i][j]=par[i-1][par[i-1][j]];
		}
	}
}

int get(int idx, int k)
{
	k--;
	int cur=idx;
	for(int i=LG-1;i>=0;i--)
	{
		if((k>>i)&1)
			cur=par[i][cur];
	}
	return cur;
}

int dp(int idx, int mask)
{
	if(idx==n+1)
	{
		if(mask==255)
			return 0;
		return -1e5;
	}
	int &ans=cache[idx][mask];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, mask);
	if(((mask>>(a[idx]-1))&1) == 0)
	{
		int nxt=get(idx, curck-1);
		if(nxt)
			ans=max(ans, curck-1 + dp(nxt, mask|(1<<(a[idx]-1))));
		nxt=get(idx, curck);
		if(nxt)
			ans=max(ans, curck + dp(nxt, mask|(1<<(a[idx]-1))));
	}
	return ans;
}


int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
		if(!g[a[i]].empty())
		{
			par[0][g[a[i]].back()]=i;
		}
		g[a[i]].push_back(i);
	}
	precompute();
	int ans=s.size();
	for(int ck=2;ck<=125;ck++)
	{
		memset(cache, -1, sizeof(cache));
		curck=ck;
		ans=max(ans, dp(1, 0));
	}	
	cout<<ans;
	return 0;
}