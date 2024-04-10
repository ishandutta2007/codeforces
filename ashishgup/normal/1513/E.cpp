//Started 40 minutes late :(


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

int n;
int sum = 0, g = 0, l = 0, e = 0, val;
int a[N];

int work()
{
	map<int, int> ml, mr;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] < val)
			ml[a[i]]++;
		else if(a[i] > val)
			mr[a[i]]++;
	}
	if(min(l, g) <= 1)
	{
		int ans = fact[n];
		map<int, int> m;
		for(int i = 1; i <= n; i++)
			m[a[i]]++;
		for(auto &it:m)
			ans = (ans * invfact[it.second]) % MOD;
		cout << ans;
		exit(0);
	}
	int lways = fact[l];
	int rways = fact[g];
	for(auto &it:ml)
		lways = (lways * invfact[it.second]) % MOD;
	for(auto &it:mr)
		rways = (rways * invfact[it.second]) % MOD;
	int midways = nCr(e + (l + g), l + g);
	int ans = (lways * rways) % MOD;
	ans = (ans * midways) % MOD;
	return ans;
}

int32_t main()
{
	IOS;
	precompute();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n)
	{
		cout << 0;
		return 0;
	}
	val = sum / n;
	for(int i = 1; i <= n; i++)
	{
		e += (a[i] == val);
		g += (a[i] > val);
		l += (a[i] < val);
	}
	if(e == n)
	{
		cout << 1;
		return 0;
	}
	int ans = 2 * work();
	ans %= MOD;
	cout << ans;
	return 0;
}