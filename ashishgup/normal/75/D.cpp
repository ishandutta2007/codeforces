#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;
const int INF=1e18;

int n, m;
int a[N], pref[N], suf[N], best[N], totsum[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		pref[i]=suf[i]=best[i]=-INF;
		int sum=0;
		for(int j=1;j<=len;j++)
		{
			cin>>a[j];
			sum+=a[j];
			pref[i]=max(pref[i], sum);
		} 
		totsum[i]=sum;
		sum=0;
		for(int j=len;j>=1;j--)
		{
			sum+=a[j];
			suf[i]=max(suf[i], sum);
		}
		int least=0;
		sum=0;
		for(int j=1;j<=len;j++)
		{
			sum+=a[j];
			best[i]=max(best[i], sum - least);
			least=min(least, sum);
		}
	}
	int prevsum=0, ans=-1e18;
	for(int i=1;i<=m;i++)
	{
		int idx;
		cin>>idx;
		ans=max(ans, best[idx]);
		ans=max(ans, prevsum + pref[idx]);
		prevsum=max(prevsum+totsum[idx], suf[idx]);
		prevsum=max(prevsum, 0LL);
	}
	cout<<ans;
	return 0;
}