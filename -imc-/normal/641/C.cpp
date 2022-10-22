#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int n, q;
	scanf("%d%d", &n, &q);
	int x = 0, l[2] = {0, 0};
	bool swp = 0;
	for(int i = 0; i < q; i++)
	{
		int t;
		scanf("%d", &t);
		if(t == 1)
		{
			int k;
			scanf("%d", &k);
			x += k;
			if(x >= n)
				x -= n;
			if(x < 0)
				x += n;
			swp ^= k & 1;
		}
		else
		{
			l[swp]++;
			l[swp ^ 1]--;
			if(l[swp] >= n)
				l[swp] -= n;
			if(l[swp ^ 1] < 0)
				l[swp ^ 1] += n;
			swp ^= 1;
		}
	}
	int ans[n];
	for(int i = 0; i < n; i++)
		ans[(i + x + l[i & 1] + 5 * n) % n] = i;
	for(auto it: ans)
		printf("%d ", it + 1);
	return 0;
}
/*
1 2 3 4 5 6
6 1 2 3 4 5
1 6 3 2 5 4
6 3 2 5 4 1

*/