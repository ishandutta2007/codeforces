#include <stdio.h>
#include <algorithm>

int arr[2010];
int cnt[5010];
int sum[5010];

int main()
{
	int n, i, j;
	double t, r = 0.0;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	std::sort(arr, arr+n);
	for(i = 0; i<n-1; i++)
		for(j = i+1; j<n; j++)
			cnt[arr[j]-arr[i]]++;

	for(i = 1; i<=5000; i++)
		sum[i] = cnt[i]+sum[i-1];

	for(i = 3; i<=5000; i++)
	{
		if(cnt[i]==0)
			continue;
		t = 0.0;
		for(j = 1; j<i-1; j++)
			t += 1.0*cnt[j]*sum[i-j-1];
		r += cnt[i]*t;
	}

	printf("%.10lf", 8.0*r/n/n/n/(n-1)/(n-1)/(n-1));
	return 0;
}