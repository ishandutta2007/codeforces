#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long long tune[100001];
long long sub[100001];
long long sum[100001];

long long bin_search(long long num)
{
	long long left = 1, right = n - 1;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (sub[mid] >= num && sub[mid - 1] < num)
			return mid-1;
		else if (mid == n - 1 && sub[mid] < num)
			return mid;
		else if (sub[mid] >= num)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &tune[i]);

	sort(tune, tune + n);

	for (int i = 1; i < n; i++)
		sub[i] = tune[i] - tune[i - 1];

	sort(sub, sub + n);

	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + sub[i];

	int q;
	scanf("%d", &q);
	while (q--)
	{
		long long l, r;
		scanf("%lld%lld", &l, &r);
		r -= l;
		r++;

		long long result = r;
		long long mid = bin_search(r);

		result += sum[mid];
		result += (n - mid -1)*r;

		printf("%lld ", result);
	}
}