#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;
const int MOD=1e9+7;

int n, m, k;
int cache[N][N*N], cache2[N][N];
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

int get(int idx, int cur)
{
	int &ans=cache2[idx][cur];
	if(ans!=-1)
		return ans;
	int ways=nCr(n, cur);
	int have=m/n;
	if(m%n >= (idx))
		have++;
	ways=pow(ways, have, MOD);
	return ans=ways;
}	

int dp(int idx, int rem)
{
	if(idx==n+1)
		return (rem==0);
	int &ans=cache[idx][rem];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int cur=0;cur<=min(n, rem);cur++)
	{
		int ways=get(idx, cur);
		ans+=ways*dp(idx+1, rem-cur);
		ans%=MOD;
	}
	return ans;
}

int32_t main()
{
	IOS;
	precompute();
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin>>n>>m>>k;
	cout<<dp(1, k);
	return 0;
}