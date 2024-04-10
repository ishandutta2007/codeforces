#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 100000;

int main()
{
	FAST;
	int n;
	cin >> n;
	bool c[N][2];
	Loop(i, 0, n)
	{
		cin >> c[i][0];
	}
	Loop(i, 0, n)
	{
		cin >> c[i][1];
	}
	int cnt1 = 0;
	int cnt2 = 0;
	Loop(i, 0, n)
	{
		cnt1 += c[i][0] && (!c[i][1]);
		cnt2 += (!c[i][0]) && c[i][1];
	}
	if (cnt1 == 0)
		cout << -1;
	else
		cout << cnt2 / cnt1 + 1;
}