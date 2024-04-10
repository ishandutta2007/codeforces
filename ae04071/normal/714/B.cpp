#include <cstdio>
#include <algorithm>
#include <vector>

int n, arr[110000];
std::vector<int> res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	std::sort(arr, arr + n);
	int prev = arr[0];
	res.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (prev != arr[i])
		{
			res.push_back(arr[i]);
			prev = arr[i];
		}
	}

	if (res.size() > 3)
		printf("NO\n");
	else if (res.size() < 3)
		printf("YES\n");
	else
	{
		int sub = res[1] - res[0];
		if (res[2] - res[1] == sub)
			printf("YES\n");
		else
			printf("NO\n");
	}
	

	return 0;
}