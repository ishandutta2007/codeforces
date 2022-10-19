#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 300003;

int n, m;
int a[N];
int b[N];
int main()
{
	cin >> n;
	m = n;
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	printf("1 ");
	for (int i = 0; i < n; ++i)
	{
		int x;
		x = b[i];
		a[x] = 1;
		while (a[m] == 1)
		{
			--m;
		}
		printf("%d ", 1+(i + 1) - (n - m));
	}
	printf("\n");
	return 0;
}