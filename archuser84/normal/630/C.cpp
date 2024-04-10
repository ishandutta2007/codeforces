#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	__int64 pow2[100];
	pow2[0] = 1;
	int n;
	cin >> n;
	__int64 ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		pow2[i] = pow2[i - 1] * 2;
		ans += pow2[i];
	}
	cout << ans << '\n';
}