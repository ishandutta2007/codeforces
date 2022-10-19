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
#define YN(flag) flag? "YES\n": "NO\n"
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 300000;

int main()
{
	FAST;
	ll b[N];
	int n;
	cin >> n;
	Loop(i, 0, n)
		cin >> b[i];
	ll maax = 0;
	Loop(i, 0, n)
	{
		cout << b[i] + maax << ' ';
		maax = max(b[i], 0LL) + maax;
	}
}