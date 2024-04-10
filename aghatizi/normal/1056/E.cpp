#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int mod[] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const int base[] = {737 , 4001};

int t[2];

array<int , 2> pw[maxn] , h[maxn];

void prepare()
{
	for(int j = 0; j < 2; j++)
	{
		pw[0][j] = 1;
		for(int i = 1; i < maxn; i++)
			pw[i][j] = 1LL * pw[i - 1][j] * base[j] % mod[j];
	}
}

inline int get(int l , int r , int k)
{
	int ans = (h[r][k] - (1LL * h[l][k] * pw[r - l][k] % mod[k]) + mod[k]) % mod[k];
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	prepare();

	string s , tx;
	cin >> s >> tx;

	int n = s.size() , m = tx.size();

	for(int i = 0; i < m; i++)
		for(int j = 0; j < 2; j++)
			h[i + 1][j] = (1LL * h[i][j] * base[j] + tx[i]) % mod[j];

	for(auto ch : s)
		t[ch - '0']++;

	int res = 0;
	for(int sz0 = 1; sz0 * t[0] < m; sz0++)
	{
		int sz1 = (m - sz0 * t[0]) / t[1];

		if(sz0 * t[0] + sz1 * t[1] != m)
			continue;

		int sum = 0 , f = 1;
		array<int , 2> h0 , h1;

		bool is0 = 0 , is1 = 0;

		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
			{
				array<int , 2> tmp;
				for(int j = 0; j < 2; j++)
					tmp[j] = get(sum , sum + sz0 , j);

				if(is0)
				{
					for(int j = 0; j < 2; j++)
						if(h0[j] != tmp[j])
							f = 0;
				}
				else
					h0 = tmp;

				is0 = 1;
				sum += sz0;
			}
			else
			{
				array<int , 2> tmp;
				for(int j = 0; j < 2; j++)
					tmp[j] = get(sum , sum + sz1 , j);

				if(is1)
				{
					for(int j = 0; j < 2; j++)
						if(h1[j] != tmp[j])
							f = 0;
				}
				else
					h1 = tmp;

				is1 = 1;
				sum += sz1;
			}
		}

		if(h0 == h1)
			f = 0;

		res += f;
	}

	cout << res << endl;
}