#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int n;
int a[100000];

bool Bit(int i, int s)
{
	return (a[i] >> s) & 1;
}

int main()
{
	FAST
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	int ans = 0;
	LoopR(b, 0, 32)
	{
		int p = -1;
		Loop(i, 0, n)
		{
			bool bi = Bit(i, b);
			if (bi)
			{
				if (p == -1)
					p = i;
				else
					p = -2;
			}
		}
		if (p >= 0)
		{
			ans = p;
			break;
		}
	}

	cout << a[ans] << ' ';
	Loop(i, 0, n)
		if (i != ans)
		{
			cout << a[i] << ' ';
		}
}