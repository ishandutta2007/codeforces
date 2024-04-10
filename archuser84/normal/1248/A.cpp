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
	int t;
	cin >> t;
	for (Loop)
	{
		ll n, Ns[2] = { 0 };
		cin >> n;
		for (LoopN)
		{
			ll x;
			cin >> x;
			++Ns[x % 2];
		}
		ll m, Ms[2] = { 0 };
		cin >> m;
		for (LoopM)
		{
			ll x;
			cin >> x;
			++Ms[x % 2];
		}
		cout << Ns[0] * Ms[0] + Ns[1] * Ms[1] << '\n';
	}
}