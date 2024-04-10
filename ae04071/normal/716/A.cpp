#include <cstdio>

int n, c;
int arr[110000];

int main()
{
	//fflush(stdin);
	//freopen("input.txt","r",stdin);

	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; i++)
		scanf("%d", arr + i);

	int cnt = 1;
	for(int i = 0; i < n - 1; i++)
	{
		if(arr[i + 1] - arr[i] <= c)
			cnt++;
		else
			cnt = 1;
	}

	printf("%d\n", cnt);

	return 0;
}