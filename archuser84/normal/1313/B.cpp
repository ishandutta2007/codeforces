#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 200000;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, y;
		cin >> n >> x >> y;

		cout << min(max((x + y + 1) - n, 1),n) << ' ';
		cout << min(x + y - 1, n) << '\n';
	}
}