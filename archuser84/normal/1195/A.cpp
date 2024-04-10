#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
using namespace std;

int main()
{
	int n,k;
	int a[1002] = { 0 };
	cin >> n >> k;
	for (LoopN)
	{
		int x;
		cin >> x;
		++a[x];
	}
	int odds = 0;
	for (int i=1;i<=k;++i)
		odds += a[i] % 2;
	cout << n - odds / 2 << '\n';
}