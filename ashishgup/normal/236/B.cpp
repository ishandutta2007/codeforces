#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=(1LL<<30);

int a, b, c, ans=0;
int cnt[N];

void precompute()
{
	for(int i=1;i<N;i++)
	{
		for(int j=1;i*j<N;j++)
			cnt[i*j]++;
	}
}

int32_t main()
{
	IOS;
	precompute();
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=c;k++)
			{
				ans+=cnt[i*j*k];
				ans%=MOD;
			}
		}
	}
	cout<<ans;
	return 0;
}