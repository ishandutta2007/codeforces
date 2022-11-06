#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 3e5 + 20;

bool has[maxn];

int a[maxn] , x[maxn] , t[maxn] , p[maxn] , dp[maxn] , mul[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(p , p + maxn , 1);
	for(int i = 2; i < maxn; i++)
		if(p[i] == 1)
			for(int j = i; j < maxn; j += i)
				p[j] = i;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		has[a[i]] = 1;
	}

	memset(dp , 63 , sizeof dp);
	for(int i = maxn - 1; i >= 1; i--)
	{
		if(has[i])
		{
			dp[i] = 1;
			continue;
		}

		int k = (maxn - 1) / i;
		for(int j = 1; j <= k; j++)
			x[j] = has[i * j];

		for(int j = 1; j <= k; j++)
			for(int l = 2 * j; l <= k; l += j)
				x[j] += x[l];

		for(int j = 1; j <= k; j++)
		{
			int tmp = j;
			
			vector<int> shit;
			while(tmp > 1)
			{
				int x = p[tmp];
				shit.pb(x);

				while(tmp % x == 0)
					tmp /= x;
			}

			int m = shit.size() , Res = 0;

			mul[0] = 1;
			for(int mask = 0; mask < (1 << m); mask++)
			{
				if(mask > 0)
				{
					int b = __builtin_ctz(mask);
					mul[mask] = mul[mask ^ (1 << b)] * mul[1 << b];

					if(mask == (1 << b))
						mul[mask] = shit[b];
				}

				if(__builtin_popcount(mask) % 2)
					Res -= x[mul[mask]];
				else
					Res += x[mul[mask]];
			}

			if(Res > 0)
				dp[i] = min(dp[i] , dp[i * j] + 1);
		}
	}

	if(dp[1] > maxn)
		dp[1] = -1;
	cout << dp[1] << endl;
}