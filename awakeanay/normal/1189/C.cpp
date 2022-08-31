#include <iostream>

#define LMAX 18
#define MAXN 100005

int power[LMAX];
int loga[MAXN];

int main()
{
	int n;
	std::cin >> n;
	
	power[0] = 1;
	for(int i = 1; i < LMAX; i++)
		power[i] = power[i-1]*2;

	for(int i = 0; i < LMAX; i++)
	{
		if(power[i] >= n)
			break;

		loga[power[i]] = i;
	}

	int seq[n];
	int pre[n];
	for(int i = 0; i < n; i++)
	{
		std::cin >> seq[i];
		pre[i] = seq[i];
		if(i) pre[i] += pre[i-1];
	}

	int val[n][LMAX];

	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < LMAX; j++)
		{
			int k = power[j];
			val[i][j] = 0;
			if(i >= k - 1)
			{
				int a = (pre[i] - pre[i - k/2])%10;
				int b = (pre[i - k/2] - ((i >= k) ? pre[i-k] : 0))%10;

				if(a + b >= 10)
					val[i][j] = 1;
			}

			if(i >= k)
				val[i][j] += val[i-k][j];
		}
	}

	int q;
	std::cin >> q;

	for(int i = 0; i < q; i++)
	{
		int l, r;
		std::cin >> l >> r;
		l--; r--;

		int sz = r-l+1;

		int ans = 0;
		for(int i = 1; power[i] <= sz; i++)
			ans += val[r][i];

		if(l)
			for(int i = 1; power[i] <= sz; i++)
				ans -= val[l-1][i];

		std::cout << ans << std::endl;
	}
}