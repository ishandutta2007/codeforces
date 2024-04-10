#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 100001;

int n;
int a[MAXN];

int main ()
{
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i] = i;
	
	for (int i = 0; i < n / 2; i++)
		swap(a[n - i * 2], a[n - 2 * i - 1]);
	
	for (int i = 1; i < n; i++)
		printf("%d ", a[i]);
	printf("%d\n", a[n]);
    return 0;
}