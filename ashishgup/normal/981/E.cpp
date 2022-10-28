#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e4+5;
const int MOD=1e9+7;

int n, q;
int l[N], r[N], x[N], sum[N], ans[N];
vector<int> events[N];

void add(int k)
{
	for(int i=n-k;i>=0;i--)
	{
		if(sum[i]>0)
		{
			sum[i+k]+=sum[i];
			if(sum[i+k]>=MOD)
				sum[i+k]-=MOD;
			ans[i+k]|=1;
		}
	}
}

void remove(int k)
{
	for(int i=0;i<=n-k;i++)
	{
		if(sum[i+k]>0)
		{
			sum[i+k]-=sum[i];
			if(sum[i+k]<0)
				sum[i+k]+=MOD;
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>l[i]>>r[i]>>x[i];
		events[l[i]].push_back(x[i]);
		events[r[i]+1].push_back(-x[i]);
	}
	sum[0]=1;
	for(auto it:events)
	{
		for(auto j:it)
		{
			if(j<0)
				remove(abs(j));
		}
		for(auto j:it)
		{
			if(j>0)
				add(j);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(ans[i]>=1);
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(ans[i])
			cout<<i<<" ";
	return 0;
}