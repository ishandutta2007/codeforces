#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=55;

int n, m;
int a[N];
double ans=0;
double cache[N][N][N][2], nCr[N][N];

double dp(int idx, int sz, int people, int taken)
{
	if(idx==m+1)
		return ((people==0) && taken);
	double &ans=cache[idx][sz][people][taken];
	if(ans>=0)
		return ans;
	ans=0;
	for(int i=0;i<=people;i++)
	{
		int maxsz=(i+a[idx]-1)/a[idx];
		if(maxsz>sz)
			continue;
		double curm=m-idx+1;
		double others=((double)curm-1)/curm;
		double prob=nCr[people][i] * pow(1.0/curm, i) * pow(others, people-i);
		ans+=prob * dp(idx+1, sz, people-i, taken|(sz==maxsz)); 
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=0;i<N;i++)
	{
		nCr[i][0]=nCr[i][i]=1;
		for(int j=1;j<i;j++)
			nCr[i][j]=nCr[i-1][j] + nCr[i-1][j-1];
	}
	for(int sz=1;sz<=n;sz++)
	{
		double p=dp(1, sz, n, 0);
		ans+=p*sz;
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}