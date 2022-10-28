#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e3+5;

int n, k, p;
int a[N], b[N];
int cache[N][N];

int dp(int i, int j)
{
	if(i==n+1)
		return 0;
	if(j==k+1)
		return 1e15;
	int &ans=cache[i][j];
	if(ans!=-1)
		return ans;
	ans=min(dp(i, j+1), max(abs(a[i]-b[j]) + abs(p-b[j]), dp(i+1, j+1)));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
		cin>>b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+k+1);
	int ans=dp(1, 1);
	cout<<ans;
	return 0;
}