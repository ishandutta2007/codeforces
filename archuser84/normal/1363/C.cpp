#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100010;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		int cnt = 0;
		cin >> n >> x;
		Loop(i, 0, n - 1)
		{
			int u, v;
			cin >> u >> v;
			cnt += u == x;
			cnt += v == x;
		}
		if (cnt < 2 || (n & 1) == 0)
			cout << "Ayush\n";
		else
			cout << "Ashish\n";
	}
}