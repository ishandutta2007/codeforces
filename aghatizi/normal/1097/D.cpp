#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e4 + 20;
const int maxpw = 55;
const int mod = 1e9 + 7;

vector<ll> get(ll n)
{
	vector<ll> ans;
	for(ll i = 2; i * i <= n; i++)
		if(n % i == 0)
		{
			ans.pb(i);
			while(n % i == 0)
				n /= i;
		}

	if(n > 1)
		ans.pb(n);

	return ans;
}

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

ll dp[maxn][maxpw][maxpw];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	int k;
	cin >> n >> k;

	for(int i = 0; i < maxpw; i++)
		dp[0][i][i] = 1;

	for(int i = 1; i <= k; i++)
		for(int j = 0; j < maxpw; j++)
		{
			for(int k = 0; k <= j; k++)
			{
				for(int nw = k; nw <= j; nw++)
					dp[i][j][k] += dp[i - 1][nw][k];

				dp[i][j][k] %= mod;
			}

			int tmp = bpw(j + 1 , mod - 2);
			for(int k = 0; k <= j; k++)
				dp[i][j][k] = 1LL * dp[i][j][k] * tmp % mod;
		}

	vector<ll> pr = get(n);

	int res = 1;
	for(auto p : pr)
	{
		ll tn = n , c = 0;
		while(tn % p == 0)
			tn /= p , c++;

		int tmp = 0;
		for(int i = 0; i <= c; i++)
			mkay(tmp += 1LL * bpw(p % mod , i) * dp[k][c][i] % mod);

		res = 1LL * res * tmp % mod;
	}

	cout << res << endl;
}