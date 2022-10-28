#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int MOD=1e9+7;

int n, ans=1;
int a[N], fact[N], invfact[N];
map<int, int> m;

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

void factorise(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		while(x%i==0)
		{
			x/=i;
			m[i]++;
		}
	}
	if(x>1)
		m[x]++;
}

int32_t main()
{
	IOS;
	precompute();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		factorise(a[i]);
	}	
	for(auto &it:m)
	{
		ans*=nCr(n+it.second-1, n-1);
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}