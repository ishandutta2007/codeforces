#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 2000;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int sum = 0;
		Loop(i, 0, n)
		{
			int x;
			cin >> x;
			sum += x;
		}
		cout << min(sum, m) << '\n';
	}
}