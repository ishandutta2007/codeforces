#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

int arr[100010];
long long dis[100010];
long long sor[100010];

std::priority_queue<long long> pq;

int ab(int a)
{
	return a<0 ? -a : a;
}

int main()
{
	int n, i;
	long long mx = 0;
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
		scanf("%d", &arr[i]);

	for(i = 1; i<n; i++)
		dis[i] = ab(arr[i]-arr[i+1]);

	for(i = 1; i<n; i++)
		sor[i] = dis[i] * (i%2 ? -1 : 1) + sor[i-1];

	pq.push(0);
	for(i = 1; i<n; i++)
	{
		mx = std::max(mx, sor[i] + pq.top());
		pq.push(-sor[i]);
	}

	while(!pq.empty())
		pq.pop();

	for(i = 1; i<n; i++)
		sor[i] = dis[i] * (i%2 ? 1 : -1) + sor[i-1];

	pq.push(0);
	for(i = 1; i<n; i++)
	{
		mx = std::max(mx, sor[i] + pq.top());
		pq.push(-sor[i]);
	}

	printf("%lld", mx);
	return 0;
}