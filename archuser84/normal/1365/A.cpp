#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
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

const int N = 60;
int a[N][N];
int n, m;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		Loop(i, 0, n)
			Loop(j, 0, m)
				cin >> a[i][j];
		int c1 = 0, c2 = 0;
		Loop(i, 0, n)
		{
			bool f = false;
			Loop(j, 0, m)
				f |= a[i][j];
			if (!f)
				c1++;
		}
		Loop(i, 0, m)
		{
			bool f = false;
			Loop(j, 0, n)
				f |= a[j][i];
			if (!f)
				c2++;
		}
		if (min(c1, c2) & 1)
			cout << "Ashish\n";
		else cout << "Vivek\n";
	}
}