#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define mod 998244353
ll am[62][62][62], ans;
ll numwords[12][62][62];
int mxchar, n;
char inp[20];
set<vector<int> > words;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %s", inp);
		int l = strlen(inp);
		vector<int> w;
		for (int j = 0; j < l; j++)
		{
			int is = 0;
			if ('a' <= inp[j] && inp[j] <= 'z') is = inp[j]-'a';
			else if ('A' <= inp[j] && inp[j] <= 'Z') is = inp[j]-'A'+26;
			else is = inp[j] - '0'+26+26;
			mxchar = max(mxchar, is);
			w.push_back(is);
		}
		if (words.find(w) != words.end()) continue;
		vector<int> w2 = w;
		reverse(w2.begin(), w2.end());
		words.insert(w2);
		numwords[w.size()][w[0]][w[w.size()-1]]++;
		if (w2 != w) numwords[w.size()][w[w.size()-1]][w[0]]++;
	}
	for (int len = 3; len <= 10; len++)
	{
		for (int a = 0; a <= mxchar; a++)
		{
			for (int b = a; b <= mxchar; b++)
			{
				for (int c = b; c <= mxchar; c++)
				{
					ll am2 = 0;
					for (int d = 0; d <= mxchar; d++)
					{
						am2 += (numwords[len][a][d]*numwords[len][b][d]*numwords[len][c][d])%mod;
					}
					am[a][b][c] = am2%mod;
				}
			}
		}
		for (int a = 0; a <= mxchar; a++)
		{
			for (int b = a; b <= mxchar; b++)
			{
				for (int c = b; c <= mxchar; c++)
				{
					for (int d = c; d <= mxchar; d++)
					{
						ll am2 = am[a][b][c];
						am2 *= am[a][b][d];
						am2 %= mod;
						am2 *= am[a][c][d];
						am2 %= mod;
						am2 *= am[b][c][d];
						am2 %= mod;
						if (a != b) 
						{
							if (b != c)
							{
								if (c != d) am2 *= 24ll;
								else am2 *= 12ll;
							}
							else
							{
								if (c != d) am2 *= 12ll;
								else am2 *= 4ll;
							}
						}
						else
						{
							if (b != c)
							{
								if (c != d) am2 *= 12;
								else am2 *= 6;
							}
							else
							{
								if (c != d) am2 *= 4;
							}
						}
						ans += am2%mod;

					}
				}
			}
		}
	}
	ans %= mod;
	printf("%lld\n", ans);
}