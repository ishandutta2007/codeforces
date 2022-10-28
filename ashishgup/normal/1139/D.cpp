#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

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
	return pow(k, MOD - 2, MOD);
}

int mu[N], prime[N];
vector<int> primes;

void precompute()
{
	fill(prime + 2, prime + N, 1);
	mu[1] = 1;
	for(int i=2;i<N;i++)
	{
		if(prime[i])
			primes.push_back(i), mu[i] = -1;
		for(auto &it: primes)
		{
			if(i * it >= N)
				break;
			prime[i * it] = 0;
			if(i % it == 0)
			{
				mu[i * it] = 0;
				break;
			}
			else
				mu[i * it] = mu[i] * mu[it];
		}
	}
}

int n;
int ans = 0;
double dans = 0;

int32_t main()
{
	IOS;
	precompute();
	cin>>n;
	ans = 1, dans = 1;
	for(int i=2;i<=n;i++)
	{
		int f = n / i;
		dans -= 1.0 * mu[i] * f / (n -f);
		ans -= (mu[i] * f * modinv(n - f)) % MOD;
		ans += MOD;
		ans %= MOD;
	}	
	cout<<ans;
	return 0;
}