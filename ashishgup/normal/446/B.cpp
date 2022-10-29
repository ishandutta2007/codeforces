#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, m, k, p, ans=-1e18;
int a[N][N], row[N], col[N], rsum[N*N], csum[N*N];
priority_queue<int, vector<int> > pq, pq2;

int32_t main()
{
	IOS;
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			row[i]+=a[i][j];
			col[j]+=a[i][j];
		}
		pq.push(row[i]);
	}
	for(int i=1;i<=m;i++)
		pq2.push(col[i]);
	for(int i=1;i<=k;i++)
	{
		int cur=pq.top();
		pq.pop();
		rsum[i]=rsum[i-1] + cur;
		pq.push(cur-m*p);
	}
	for(int i=1;i<=k;i++)
	{
		int cur=pq2.top();
		pq2.pop();
		csum[i]=csum[i-1] + cur;
		pq2.push(cur-n*p);
	}
	for(int i=0;i<=k;i++)
		ans=max(ans, rsum[i] + csum[k-i] - i*(k-i)*p);
	cout<<ans;
	return 0;
}