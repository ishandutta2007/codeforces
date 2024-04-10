#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=100;
const int MOD=1e9+7;

int m, sz=0;
int x[15];
int cache[15][10][2], cache2[10], cache3[10][10][10];
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

int dp(int idx, int reqd, int less)
{
	if(reqd<0)
		return 0;
	if(idx==sz+1)
		return (reqd==0);
	int &ans=cache[idx][reqd][less];
	if(ans!=-1)
		return ans;
	ans=0;
	int higher=less?9:x[idx];
	int lower=0;
	for(int i=lower;i<=higher;i++)
	{
		int check=(i==4 || i==7);
		ans+=dp(idx+1, reqd-check, less|(i<x[idx]));
	}
	ans%=MOD;
	return ans;
}

int f(int reqd)
{
	if(reqd>9)
		return 0;
	int &ans=cache2[reqd];
	if(ans!=-1)
		return ans;
	memset(cache, -1, sizeof(cache));
	sz=0;
	int n=m;
	while(n>0)
	{
		x[++sz]=n%10;
		n/=10;
	}
	reverse(x+1, x+sz+1);
	ans=dp(1, reqd, 0);
	if(reqd==0)
		ans--;
	return ans;
}

int bignCr(int n, int r)
{
	int ans=1;
	for(int i=n;i>=n-r+1;i--)
	{
		ans*=i;
		ans%=MOD;
	}
	for(int i=2;i<=r;i++)
	{
		ans*=modinv(i);
		ans%=MOD;
	}
	return ans;
}	

int dp2(int mx, int cur, int taken)
{
	if(mx<0)
		return 0;
	if(cur==10)
		return (taken==6);
	int &ans=cache3[mx][cur][taken];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int taking=0;taking<=6-taken;taking++)
	{
		int ways=nCr(6-taken, taking);
		ways*=bignCr(f(cur), taking);
		ways%=MOD;
		ways*=fact[taking];
		ways%=MOD;
		ans+=ways*dp2(mx-cur*taking, cur+1, taken+taking);
	}
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	precompute();
	memset(cache2, -1, sizeof(cache2));
	memset(cache3, -1, sizeof(cache3));
	cin>>m;
	int ans=0;
	for(int i=1;i<=9;i++)
	{
		ans+=f(i) * dp2(i-1, 0, 0);
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}