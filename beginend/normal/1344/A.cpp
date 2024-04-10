#include<bits/stdc++.h>
using namespace std;

const int N=200005;

int n, a[N];
map<int, int> ma;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		ma.clear();
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			a[i] %= n;
			a[i] = (a[i] + n) % n;
			if (ma[i + a[i]] || ma[i + a[i] - n]) flag = 1;
			ma[i + a[i]] = 1;
		}
		puts(flag ? "NO" : "YES");
	}
	return 0;
}