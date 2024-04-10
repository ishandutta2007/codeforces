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
	__int64 n, k;
	cin >> n >> k;
	__int64 ans = -1.5 + sqrt(2.25 + 2 * k + 2 * n);
	cout << ans * (ans + 1) / 2 - k << '\n';
}