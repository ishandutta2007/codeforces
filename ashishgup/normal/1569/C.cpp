#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
const int MOD = 998244353;

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

int n;
int a[N];

int32_t main()
{
	IOS;
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		map<int, int> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		int mx = a[n];
		int mx2 = a[n - 1];
		if(mx == mx2)
		{
			int ans = fact[n];
			cout << ans << endl;
		}
		else if(mx > mx2 + 1)
			cout << 0 << endl;
		else
		{
			int totalWays = fact[n];
			int invalidWays = fact[n] * modinv(m[mx2] + 1); //All 2nd max occur before max
			invalidWays %= MOD;
			int ans = (totalWays - invalidWays + MOD) % MOD;
			cout << ans << endl;
		}
	}
	return 0;
}