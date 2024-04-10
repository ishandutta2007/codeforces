#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int M=1LL<<10;
const int MOD=1e9+7;

int n, k, others=0, cnt=-1;
int a[N], sz[N], cache[M][M];
map<int, int> idx;
int fact[N], invfact[N];

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

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}

int checklucky(int x)
{
	int check=1;
	while(x>0)
	{
		int cur=x%10;
		x/=10;
		check&=(cur==4 || cur==7);
	}
	return check;
}

int dp(int idx, int taken)
{
	if(taken>k)
		return 0;
	if(idx==cnt+1)
	{
		int to_take=k-taken;
		if(to_take>others)
			return 0;
		int ans=nCr(others, to_take);
		return ans;
	}
	int &ans=cache[idx][taken];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, taken);
	ans+=(sz[idx]*(dp(idx+1, taken+1)));
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	precompute();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		others+=!checklucky(a[i]);
		if(checklucky(a[i]))
		{
			if(idx.find(a[i])==idx.end())
				idx[a[i]]=++cnt;
			sz[idx[a[i]]]++;
		}	
	}
	int ans=dp(0, 0);
	cout<<ans;
	return 0;
}