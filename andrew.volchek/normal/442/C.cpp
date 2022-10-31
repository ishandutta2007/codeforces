#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 500005;

int a[maxn], p[maxn], nx[maxn], pr[maxn], del[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		p[i] = i;
		nx[i] = i + 1;
		pr[i] = i - 1;
	}
	
	sort(p, p + n, [&](int i, int j) { return a[i] < a[j]; });
	
	if (n <= 2)
	{
		printf("%d", 0);
		return 0;
	}
	
	long long ans = 0;
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (p[i] == n - 1 || !p[i])
			continue;
			
		int j = p[i];
			
		if (nx[j] == r && a[j] > a[r])
		{
			r = j;
			continue;
		}
		
		if (pr[j] == l && a[j] > a[l])
		{
			l = j;
			continue;
		}
			
		ans += min(a[nx[j]], a[pr[j]]);
		del[j] = 1;
		nx[pr[j]] = nx[j];
		pr[nx[j]] = pr[j];
	}
	
	vector < int > b;
	int p = 0;
	
	while (p != n)
	{
		b.push_back(a[p]);
		p = nx[p];
	}
	
	sort(b.begin(), b.end());
	for (int i = 0; i < b.size() - 2; i++)
		ans += b[i];
	
	
	cout << ans << endl;
	
	return 0;
}