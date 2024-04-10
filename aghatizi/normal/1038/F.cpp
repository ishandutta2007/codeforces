#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 50;
const int maxm = (1 << 20) + 100;

int f[maxn] , nxt[maxn][2];

ll dp[maxn][maxn][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	ll show = 0;
	for(auto ch : s)
	{
		show <<= 1;
		show |= (ch == '1');
	}

	int m = (int)s.size();

	if(m >= n / 2)
	{
		ll res = 0;
		int k = n - m;

		set<ll> st;
		for(int mask = 0; mask < (1 << k); mask++)
		{
			ll tmp = show;
			for(int i = 0; i < k; i++)
			{
				tmp <<= 1;
				tmp |= bit(mask , i); 
			}

			ll Mn = tmp , St = tmp , T = 1;
			for(int i = 0; i < n; i++)
			{
				if(tmp&1)
				{
					tmp >>= 1;
					tmp |= (1LL << (n - 1));
				}
				else
					tmp >>= 1;

				if(tmp == St)
					break;
				Mn = min(Mn , tmp);
				T++;
			}

			if(st.count(Mn))
				continue;
			st.insert(Mn);
			res += T;
		}

		cout << res << endl;
		return 0;
	}

	for(int i = 1; i < m; i++)
	{
		int k = f[i];

		while(k > 0 && s[k] != s[i])
			k = f[k];
		if(s[k] == s[i])
			k++;

		f[i + 1] = k;
	}

	for(int i = 0; i <= m; i++)
		for(int j = 0; j < 2; j++)
		{
			if(i < m && s[i] == j + '0')
				nxt[i][j] = i + 1;
			else
				nxt[i][j] = nxt[f[i]][j];
		}

	ll res = 0;
	for(int mask = 0; mask < (1 << m); mask++)
	{
		memset(dp , 0 , sizeof dp);

		string shit;
		for(int i = 0; i < m; i++)
			shit += '0' + bit(mask , i);

		int S = 0;
		for(int i = 0; i < m; i++)
			S = nxt[S][shit[i] - '0'];

		dp[0][S][S == m] = 1;

		for(int i = 0; i < n - m; i++)
			for(int j = 0; j <= m; j++)
				for(int k = 0; k < 2; k++)
					for(int nc = 0; nc < 2; nc++)
					{
						int tmp = nxt[j][nc];
						dp[i + 1][tmp][k | (tmp == m)] += dp[i][j][k];
					}

		for(int j = 0; j <= m; j++)
			res += dp[n - m][j][1];

		for(int i = 0; i < m; i++)
		{
			int S = i;

			bool f = 0;
			for(int j = 0; j < m; j++)
			{
				S = nxt[S][shit[j] - '0'];

				if(S == m)
				{
					f = 1;
					break;
				}
			}

			if(f)
				res += dp[n - m][i][0];
		}
	}

	cout << res << endl;
}