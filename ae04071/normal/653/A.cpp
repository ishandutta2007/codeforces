#include <iostream>
#include <cstdio>
#include <algorithm>

int main()
{
	int n;

	int* arr;
	
	scanf("%d", &n);

	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	std::sort(arr, arr + n);

	int count = 1;
	bool check = false;

	for (int i = 1; i < n; i++)
	{
		if (abs(arr[i] - arr[i - 1]) <= 1 && arr[i] != arr[i - 1])
		{
			count++;
		}
		else if (arr[i] == arr[i - 1]);
		else
			count = 1;
		
		if (count == 3)break;
	}

	if (count == 3) printf("Yes\n");
	else printf("No\n");

	delete arr;

	return 0;
}