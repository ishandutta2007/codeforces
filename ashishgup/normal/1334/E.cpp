#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;
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

struct data
{
	int u, v, idx;
};

int n, q;
vector<int> v;
int ans[N];

int get(int x, int div)
{
	int ans = 0;
	while(x % div == 0)
	{
		x /= div;
		ans++;
	}
	return ans;
}

int32_t main()
{
	IOS;
	precompute();
	cin >> n;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i)
			continue;
		while(n % i == 0)
			n /= i;
		v.push_back(i);
	}
	if(n > 1)
		v.push_back(n);
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		int uu, vv;
		cin >> uu >> vv;
		if(uu > vv)
			swap(uu, vv);
		int g = __gcd(uu, vv);
		int ans = 1, sum = 0, sum2 = 0;
		for(auto &it:v)
		{
			int ct = abs(get(vv, it) - get(g, it));
			sum += ct;
			ans *= invfact[ct];
			ans %= MOD;
			int ct2 = abs(get(uu, it) - get(g, it));
			sum2 += ct2;
			ans *= invfact[ct2];
			ans %= MOD;
		}
		ans *= fact[sum];
		ans %= MOD;
		ans *= fact[sum2];
		ans %= MOD;
		cout << ans << endl;
	}
	return 0;
}