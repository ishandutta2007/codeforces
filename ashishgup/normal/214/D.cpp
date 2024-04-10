#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;
const int MOD=1e9+7;

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

int n, sum=0;
int a[N];
int cache[10][N];

int dp(int dig, int len)
{
	if(dig==1)
	{
		if(len<a[1])
			return 0;
		return 1;
	}
	int &ans=cache[dig][len];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int i=a[dig];i<=len;i++)
	{
		int cur=nCr(len, i) * dp(dig-1, len-i);
		cur%=MOD;
		ans+=cur;
		ans%=MOD;
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	precompute();
	cin>>n;
	for(int i=0;i<=9;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int ans=0;
	for(int len=sum;len<=n;len++)
	{
		for(int zeros=a[0];zeros<=len;zeros++)
		{
			ans+=nCr(len-1, zeros) * dp(9, len-zeros);
			ans%=MOD;
		}
	}
	cout<<ans;
	return 0;
}