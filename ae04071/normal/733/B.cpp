#include <cstdio>
#include <cstring>
#include <utility>
#define ABS(a) ((a<0)?-a:a)

int n;
std::pair<int, int> arr[100010];
int main()
{
	int lSum = 0, rSum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].first, &arr[i].second);
		lSum += arr[i].first, rSum += arr[i].second;
	}

	int max = ABS((rSum - lSum)), idx = 0;
	for (int i = 0; i < n; i++)
	{
		int tl = lSum - arr[i].first + arr[i].second;
		int tr = rSum - arr[i].second + arr[i].first;
		if (ABS((tl - tr)) > max)
		{
			max = ABS((tl - tr));
			idx = i + 1;
		}
	}
	printf("%d\n", idx);

	return 0;
}