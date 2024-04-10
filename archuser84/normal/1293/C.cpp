#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	bool m[2][200000] = { 0 };
	Loop(loop, 0, t)
	{
		int r, c;
		cin >> r >> c;
		r--; c--;
		m[r][c] = !m[r][c];
		int x = m[r][c] * 2 - 1;
		int c1 = c + ((!r) * 2 - 1);
		int c3 = c - ((!r) * 2 - 1);
		if (c1 >= 0 && c1 < n && m[!r][c1])
			count1 += x;
		if (m[!r][c])
			count2 += x;
		if (c3 >= 0 && c3 < n && m[!r][c3])
			count3 += x;
		if (count1 == 0 && count2 == 0 && count3 == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
}