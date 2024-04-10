#include <bits/stdc++.h>
using namespace std;

int p[1123456];
bool been[1123456];
int tab[1123456];
bool ok[1123456];
int cnt[1123456];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
		
	int odd = 0;
	vector<int> c;
	
	for (int i = 1; i <= n; i++)
		if (!been[i])
		{
			int sz = 1;
			int x = p[i];
			while (x != i)
			{
				been[x] = true;
				x = p[x];
				been[x] = true;
				sz++;
			}
			
			if (sz % 2 == 1)
				odd++;

			c.push_back(sz);
		}
	
	sort(c.begin(), c.end());
	
	for (int i = 0; i < c.size(); i++)
		cnt[c[i]]++;
	
	tab[0] = 0;
	ok[0] = true;
	
	for (int i = 1; i <= k; i++)
	{
		if (cnt[i] == 0)
			continue;

		if (cnt[i] == 1)
		{
			for (int j = k - 1; j >= 0; j--)
				if (ok[j])
					ok[j + i] = true;
		}
		else
		{
			memset(tab, 0, sizeof(int) * (k + 1));
			for (int j = 0; j < k; j++)
				if (ok[j] && tab[j] < cnt[i])
				{
					if (ok[j + i])
						tab[j + i] = min(tab[j + i], tab[j] + 1);
					else
					{
						tab[j + i] = tab[j] + 1;	
						ok[j + i] = true;
					}
				}
		}
	}
	
	int ans2 = min(n, min(2*k, (n - odd)) + max(k - (n - odd) / 2, 0));
	cout << (ok[k] ? k : (k+1)) << " " << ans2 << endl;
}