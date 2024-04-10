#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int M=sqrt(N) + 1;

int n, q;
int a[N], cache[N][M];
;
int dp(int p, int k)
{
	if(p>n)
		return 0;
	if(cache[p][k]!=-1)
		return cache[p][k];
	return cache[p][k] = 1 + dp(p+a[p]+k, k);
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>q;
	while(q--)
	{
		int p, k;
		cin>>p>>k;
		if(k>=M)
		{
			int ans=0;
			while(p<=n)
			{
				ans++;
				p=p+a[p]+k;
			}
			cout<<ans<<endl;
		}
		else
		{
			int ans=dp(p, k);
			cout<<ans<<endl;
		}
	}
	return 0;
}