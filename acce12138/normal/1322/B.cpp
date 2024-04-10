#include <bits/stdc++.h>

const int maxn = 400111;
int n, a[maxn], b[maxn];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	int ans = 0;
	for(int i=0; i<25; i++)
	{
		for(int j=1; j<=n; j++) b[j] = a[j] & ((1<<i+1) - 1);
		std::sort(b+1, b+n+1);
		long long sum = 0;
		for(int j=1; j<=n; j++)
		{
			int lb = 1<<i, rb = 0, bb = a[j] & ((1<<i+1)-1);
			lb -= bb; if(lb < 0) lb += (1<<i+1);
			rb -= bb; if(rb < 0) rb += (1<<i+1);
			int val = std::lower_bound(b+1, b+n+1, rb) - std::lower_bound(b+1, b+n+1, lb);
			if(lb > rb) val += n;
			if((a[j]*2) & (1<<i)) val--;
			sum += val;
		}
		sum /= 2;
		if(sum & 1) ans |= 1<<i;
	}
	printf("%d\n", ans);
	return 0;
}