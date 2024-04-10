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
	int n, m;
	cin >> n >> m;
	string s[30], u[30];
	for (LoopN)
		cin >> s[i];
	for (LoopM)
		cin >> u[j];
	int t;
	cin >> t;
	for (Loop)
	{
		int y;
		cin >> y; --y;
		cout << s[y % n] << u[y % m] << '\n';
	}
}