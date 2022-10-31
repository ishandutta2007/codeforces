#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, m, a[N], c[N], tmp[N];

bool check(int k)
{
	for (int i = 1; i <= m; i++)
		if ((LL) c[i] * k >= n) tmp[i] = n;
		else tmp[i] = c[i] * k;
	int p = m;
	for (int i = n; i >= 1; i--)
	{
		while (p > 0 && !tmp[p]) p--;
		if (p < a[i]) return 0;
		tmp[p]--;
	}
	return 1;
}

void pri(int k)
{
	for (int i = 1; i <= m; i++)
		if ((LL) c[i] * k >= n) tmp[i] = n;
		else tmp[i] = c[i] * k;
	int p = m;
	vector<int> vec[k];
	for (int i = n; i >= 1; i--)
	{
		while (p > 0 && !tmp[p]) p--;
		vec[(tmp[p] - 1) / c[p]].push_back(a[i]);
		tmp[p]--;
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", vec[i].size());
		for (int x : vec[i])
			printf("%d ", x);
		puts("");
	}	
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i=1; i<= m; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= m; i++) c[i] -= c[i + 1];
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	pri(r + 1);
	return 0;
}