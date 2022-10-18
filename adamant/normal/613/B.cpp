#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, A, cf, cm, m;
	cin >> n >> A >> cf >> cm >> m;
	int sk[++n];
	sk[n - 1] = A;
	for(int i = 0; i < n - 1; i++)
		cin >> sk[i];
	int p[n];
	iota(p, p + n, 0);
	sort(p, p + n, [&](int a, int b){return sk[a] < sk[b];});
	int ans = 0;
	int j = n;
	int lvl = A;
	int sum = 0;
	for(int i = 1; i < n; i++)
	{
		sum += (sk[p[i]] - sk[p[i - 1]]) * i;
		if(sum > m)
		{
			sum -= (sk[p[i]] - sk[p[i - 1]]) * i;
			lvl = sk[p[i - 1]] + (m - sum) / i;
			sum += ((m - sum) / i) * i;
			j = i;
			break;
		}
	}
	//cout << j << ' ' << lvl << ' ' << sum << endl;
	if(lvl == A)
	{
		cout << (n - 1) * cf + A * cm << "\n";
		for(int i = 0; i < n - 1; i++)
			cout << A << ' ';
		return 0;
	}
	int oj = j, oi = 0;
	int sum_bk = 0;
	for(int i = 1; i <= n; i++)
	{
		//cout << i << ' ' << j << endl;
		sum_bk += A - sk[p[n - i]];
if(n - i + 1 == j)
{
sum -= (lvl - sk[p[j - 1]]);
j--;
}
		if(sum_bk > m)
			break;
		while(sum_bk + sum > m || j > n - i)
		{
			//cout << sum << ' ' << j << ' ' << lvl << endl;
			sum -= (lvl - sk[p[j - 1]]) * j;
			//cout << sum << ' ' << j << ' ' << lvl << endl;
			if(sum + sum_bk <= m && j <= n - i)
			{
				sum += (lvl - sk[p[j - 1]]) * j;
				int delta = (sum + sum_bk - m + j - 1) / j;
				//cout << delta << endl;
				lvl -= delta;
				sum -= (delta) * j;
			}
			else
			{
				lvl = sk[p[j - 1]];
				j--;
			}
		}
		if((i - 1) * cf + lvl * cm > ans)
		{
			oi = i;
			oj = lvl;
			ans = (i - 1) * cf + lvl * cm;
		}
	}
	//cout << "  " << oi << ' ' << oj << endl;
	cout << ans << "\n";
	for(int i = 0; i < n - 1; i++)
	{
		sk[p[i]] = max(sk[p[i]], oj);
		if(i + oi >= n)
			sk[p[i]] = A;
	}
	for(int i = 0; i < n - 1; i++)
		cout << sk[i] << ' ';
	cout << "\n";
	
}