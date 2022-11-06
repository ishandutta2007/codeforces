#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 40;
const int maxm = (1 << 10) + 20;
const int mod = 998244353;

int cnt[maxn][maxm] , sum[maxn][maxm] , k , pw10[maxn];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int solve(ll R)
{
	if(R == 0)
		return 0;

	string r;
	while(R)
	{
		r += (char)(R % 10);
		R /= 10;
	}

	reverse(r.begin() , r.end());

	int now = 0 , res = 0 , shit = 0;
	for(int i = 0; i < (int)r.size(); i++)
	{
		for(int j = 0; j < r[i]; j++)
		{
			int tmpnow = (now | (1 << j)) , rem = (int)r.size() - i - 1;
			int ts = (1LL * shit * 10 + j) % mod;

			mkay(res += sum[rem][tmpnow]);
			mkay(res += (1LL * ts * pw10[rem] % mod) * cnt[rem][tmpnow] % mod);
		}

		now |= (1 << r[i]);
		shit = (1LL * shit * 10 + r[i]) % mod;
	}

	mkay(res += 1LL * shit * cnt[0][now] % mod);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll l , r;
	cin >> l >> r >> k;

	pw10[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw10[i] = 1LL * pw10[i - 1] * 10 % mod;

	for(int mask = 0; mask < (1 << 10); mask++)
		if(__builtin_popcount(mask) <= k)
			cnt[0][mask] = 1;

	for(int i = 1; i < maxn; i++)
		for(int mask = 0; mask < (1 << 10); mask++)
			for(int j = 0; j < 10; j++)
			{
				int nmask = (mask | (1 << j));
				if(mask == 1)
				{
					cnt[i][mask] = cnt[i][0];
					sum[i][mask] = sum[i][0];

					continue;
				}

				mkay(cnt[i][mask] += cnt[i - 1][nmask]);
				mkay(sum[i][mask] += sum[i - 1][nmask]);
				mkay(sum[i][mask] += (1LL * j * cnt[i - 1][nmask] % mod * pw10[i - 1] % mod) % mod);
			}

	l--;

	int ans = solve(r);
	mkay(ans -= solve(l));

	cout << ans << endl;
}