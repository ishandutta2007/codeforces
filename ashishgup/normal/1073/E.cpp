#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1<<10;
const int MOD=998244353;

int l, r, k;
int sz=0, x[N];
int cache[20][N][2], cache2[20][N][2];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int cntbits(int &x)
{
	return __builtin_popcountll(x);
}

int dp2(int idx, int mask, int less)
{
	if(cntbits(mask)>k)
		return 0;
	if(idx==sz+1)
		return 1;
	int &ans=cache2[idx][mask][less];
	if(ans!=-1)
		return ans;
	ans=0;
	int lim=(less?9:x[idx]);
	for(int i=0;i<=lim;i++)
	{
		ans+=dp2(idx+1, mask|(1<<i), less|(i<x[idx]));
		ans%=MOD;
	}
	return ans;
}

int dp(int idx, int mask, int less, int strt)
{
	if(cntbits(mask)>k)
		return 0;
	if(idx==sz+1)
		return 0;
	int &ans=cache[idx][mask][less];
	if(ans!=-1)
		return ans;
	ans=0;
	int lim=(less?9:x[idx]);
	if(strt)
	{
		for(int i=0;i<=lim;i++)
		{
			int ways=dp2(idx+1, mask|(1<<i), less|(i<x[idx]));
			int value=(i*pow(10LL, sz-idx, MOD))%MOD;
			value*=ways;
			value%=MOD;
			ans+=value;
			ans+=dp(idx+1, mask|(1<<i), less|(i<x[idx]), strt);
			ans%=MOD;
		}
	}
	else
	{
		for(int i=1;i<=lim;i++)
		{
			int ways=dp2(idx+1, mask|(1<<i), less|(i<x[idx]));
			int value=(i*pow(10LL, sz-idx, MOD))%MOD;
			value*=ways;
			value%=MOD;
			ans+=value;
			ans+=dp(idx+1, mask|(1<<i), less|(i<x[idx]), 1);
			ans%=MOD;
		}
		ans+=dp(idx+1, mask, 1, 0);
		ans%=MOD;
	}
	return ans;
}

int f(int n)
{
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	sz=0;
	while(n>0)
	{
		x[++sz]=n%10;
		n/=10;
	}
	reverse(x+1, x+sz+1);
	int ans=dp(1, 0, 0, 0);
	return ans;
}

int32_t main()
{
	IOS;
	cin>>l>>r>>k;
	int ans=f(r) - f(l-1) + MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}