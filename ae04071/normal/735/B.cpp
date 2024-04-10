#include <stdio.h>
#include <algorithm>

int n, n1, n2;
int arr[100000];

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main()
{
	scanf("%d %d %d", &n, &n1, &n2);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	std::sort(arr, arr + n, cmp);
	if (n1 > n2)
		std::swap(n1, n2);
	double sum = 0;
	double res = 0;
	
	for (int i = 0; i < n1; i++)
		res += arr[i];
	res /= n1;
	sum += res;
	
	res = 0;
	for (int i = n1; i < n1 + n2; i++) {
		res += arr[i];
	}
	res /= n2;
	sum += res;

	printf("%.8lf\n", sum);

	return 0;
}