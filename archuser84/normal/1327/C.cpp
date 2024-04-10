#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 200;

int main()
{
	FAST;
	int n, m, k;
	cin >> n >> m >> k;
	Loop(i, 0, 4 * k)
	{
		int x;
		cin >> x;
	}
	cout << n + m - 2 + n * m - n % 2 << '\n';
	Loop(i, 0, n - 1)
		cout << 'U';
	Loop(i, 0, m - 1)
		cout << 'L';
	Loop(x, 0, n / 2)
	{
		Loop(i, 0, m - 1)
			cout << 'R';
		cout << 'D';
		Loop(i, 0, m - 1)
			cout << 'L';
		cout << 'D';
	}
	if (n % 2)
	{
		Loop(i, 0, m - 1)
			cout << 'R';
	}
}