#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=4001;
const int INF=1e9;
const int K=sqrt(2*N) + 1;

int n;
int a[N], pref[N];
bool vis[2][N-1000][2*K][K];
int cache[2][N-1000][2*K][K];

int get(int l, int r)
{
	return pref[r] - pref[l-1];
}

int dp(int player, int l, int r, int k)
{
	int diff=r-l;
	int &ans=cache[player][l][diff+K][k];
	if(vis[player][l][diff+K][k])
		return ans;
	vis[player][l][diff+K][k]=1;
	if(!player)
	{
		ans=-INF;
		if(l+k-1<=r)
			ans=max(ans, get(l, l+k-1) + dp(player^1, l+k, r, k));
		if(l+k<=r)
			ans=max(ans, get(l, l+k) + dp(player^1, l+k+1, r, k+1));
		if(l+k-1>r)
			ans=0;
	}
	else
	{
		ans=INF;
		if(r-k+1>=l)
			ans=min(ans, -1*get(r-k+1, r) + dp(player^1, l, r-k, k));
		if(r-k>=l)
			ans=min(ans, -1*get(r-k, r) + dp(player^1, l, r-k-1, k+1));
		if(r-k+1<l)
			ans=0;
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
		pref[i]=pref[i-1] + a[i];
	}
	int ans=dp(0, 1, n, 1);
	cout<<ans;
	return 0;
}