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
	bool ans = 1;
	int n;
	cin >> n;
	for (LoopN)
	{
		int x;
		cin >> x;
		if (x % 2)
			ans = 0;
	}
	if (ans)
		cout << "Second\n";
	else
		cout << "First\n";
}