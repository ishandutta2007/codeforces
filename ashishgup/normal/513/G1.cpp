#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=35;
const int M=205;

int n, k;
int a[N], idx[N];
double ans=0;
bool vis[N][N][M];
double cache[N][N][M];

int newidx(int i, int l, int r)
{
	if(i<l || i>r)
		return i;
	int gap=(i-l);
	int idx=(r-gap);
	return idx;
}

double dp(int idx1, int idx2, int k) //smaller idx, larger idx
{
	if(k==0)
		return (idx1>idx2);
	if(vis[idx1][idx2][k])
		return cache[idx1][idx2][k];
	vis[idx1][idx2][k]=1;
	double &ans=cache[idx1][idx2][k];
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int newi=newidx(idx1, i, j);
			int newj=newidx(idx2, i, j);
			ans+=dp(newi, newj, k-1);
		}
	}
	ans/=(n*(n+1)/2);
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		idx[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=dp(idx[i], idx[j], k);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}