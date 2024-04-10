#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define mp(a, b) std::make_pair(a, b)

const int mod = 1000000007;

std::vector<int> arr[100000];
int num[1000001];
int fac[1000001];

std::vector<std::pair<int, int> > tmp;
std::vector<std::pair<int, int> > tmp2;

int main()
{
	int c = 1, p, t, n, m, g, x, i, j, k;
	scanf("%d%d", &n, &m);

	for(i = 0; i<n; i++)
	{
		scanf("%d", &g);
		for(j = 0; j<g; j++)
		{
			scanf("%d", &x);
			arr[i].push_back(x);
		}
	}

	for(i = 0; i<n; i++)
	{
		std::sort(arr[i].begin(), arr[i].end());

		tmp.clear();
		p = -1;
		for(j = 0; j<arr[i].size(); j++)
		{
			if(j == arr[i].size()-1 || arr[i][j] != arr[i][j+1])
			{
				tmp.push_back(mp(j-p, arr[i][j]));
				p = j;
			}
		}

		std::sort(tmp.begin(), tmp.end());

		tmp2.clear();
		for(j = 0; j<tmp.size(); j++)
		{
			t = tmp[j].second;
			tmp2.push_back(mp(num[t], t));

			if(j == tmp.size()-1 || tmp[j].first != tmp[j+1].first)
			{
				std::sort(tmp2.begin(), tmp2.end());

				for(k = 0; k<tmp2.size(); k++)
				{
					t = tmp2[k].second;
					num[t] = c;

					if(k == tmp2.size()-1 || tmp2[k].first != tmp2[k+1].first)
						c++;
				}

				tmp2.clear();
			}
		}
	}

	long long res = 1;

	fac[1] = 1;
	for(i = 2; i<=m; i++)
		fac[i] = 1LL*fac[i-1]*i %mod;

	std::sort(num+1, num+m+1);

	p = 0;
	for(i = 1; i<=m; i++)
	{
		if(i==m || num[i] != num[i+1])
		{
			res = 1LL*res*fac[i-p] %mod;
			p = i;
		}
	}

	printf("%lld", res);
	return 0;
}