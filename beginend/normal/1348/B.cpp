#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, k, s[N], a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) s[i] = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[a[i]]++;
		int cnt = 0;
		vector<int> vec;
		for (int i = 1; i <= n; i++) if (s[i]) vec.push_back(i), cnt++;
		if (cnt > k)
		{
			puts("-1");
			continue;
		}
		printf("%d\n", n * k);
		for (int i = 1; i <= n; i++)
			for (int j = 1, p = 0; j <= k; j++, (p += 1) %= cnt)
				printf("%d ", vec[p]);
		puts("");
	}
	return 0;
}