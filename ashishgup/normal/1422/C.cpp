#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

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

string s;
int store[N];

int32_t main()
{
	IOS;
	precompute();
	cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i = 0; i <= n; i++)
	{
		store[i] = pow(10, i, MOD) * (i + 1);
		store[i] %= MOD;
		if(i - 1 >= 0)
		{
			store[i] += store[i - 1];
			store[i] %= MOD;
		}
	}
	for(int i = 0; i < n; i++)
	{
		int x = n - 1 - i;
		if(x - 1 >= 0)
			ans += (s[i] - '0') * store[x - 1];
		ans %= MOD;
		int lhs = i;
		lhs = (lhs * (lhs + 1)) / 2;
		lhs %= MOD;
		ans += (s[i] - '0') * pow(10, n - 1 - i, MOD) * lhs;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}