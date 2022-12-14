#include<bits/stdc++.h>
using namespace std;

int s[1010101], a[1010101];
int per[1010101];
int idx[1010101];

int n, m;
void add(int* ss, int p)
{
	for(int i = p; i <= m; i += (i & -i))
		ss[i]++;
}

int sum(int* ss, int p)
{
	int ret = 0;
	for(int i = p; i > 0; i -= (i & -i))
		ret += ss[i];
	return ret;
}

bool cmp(const int &x, const int &y)
{
	if(a[x] != a[y])
		return a[x] < a[y];
	return x < y;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		s[0] = 0;
		for(int i = 1; i <= n * m; i++)
		{
			scanf("%d", &a[i]);
			per[i] = i;
			s[i] = 0;
		}

		sort(per + 1, per + n * m + 1, cmp);

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				for(int k = j; k <= m + 1; k++)
				if(a[per[(i - 1) * m + j]] != a[per[(i - 1) * m + k]] || k == m + 1)
				{
					reverse(per + (i - 1) * m + j, per + (i - 1) * m + k);
					j = k - 1;
					break;
				}
			}
		}
		for(int i = 1; i <= n * m; i++)
			idx[per[i]] = i;

		long long ans = 0;
		for(int i = 1; i <= n * m; i++)
		{
			ans += sum(s + (idx[i] - 1) / m * m, (idx[i] - 1) % m + 1);
			add(s + (idx[i] - 1) / m * m, (idx[i] - 1) % m + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}