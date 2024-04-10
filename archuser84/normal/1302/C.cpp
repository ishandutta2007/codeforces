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

const int N = 100000;

int main()
{
	FAST;
	int x = 0, y = 0, z = 0;
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		x += a; y += b; z += c;
	}
	if (!x && !y && !z)
		cout << "YES\n";
	else
		cout << "NO\n";
}