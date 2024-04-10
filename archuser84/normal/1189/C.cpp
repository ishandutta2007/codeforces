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
	int n;
	int s[100001]; s[0] = 0;
	cin >> n;
	Loop(i, 1, n + 1)
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int l, r;
		cin >> l >> r;
		cout << (s[r] - s[l - 1]) / 10 << '\n';
	}
}