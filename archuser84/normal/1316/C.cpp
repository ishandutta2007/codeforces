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

const int N = 1000000;

int main()
{
	FAST;
	int n, m;
	int a[N], b[N], p;
	cin >> n >> m >> p;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, m)
		cin >> b[i];
	int p1=0, p2=0;
	while (true)
	{
		if (a[p1] % p == 0)
		{
			p1++;
			continue;
		}
		if (b[p2] % p == 0)
		{
			p2++;
			continue;
		}
		break;
	}
	cout << p1 + p2;
}