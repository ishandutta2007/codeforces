#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 200010;
int n;
bool inff = 0;
int a[N];

int getNum(int p, int c)
{
	switch (10 * p + c)
	{
	case 11: inff = true; return -1;
	case 12: return 3;
	case 13: return 4;
	case 21: return 3;
	case 22: inff = true; return -1;
	case 23: inff = true; return -1;
	case 31: return 4;
	case 32: inff = true; return -1;
	case 33: inff = true; return -1;
	default: return -1;
	}
}

int main()
{
	cin >> n;
	cin >> a[0];
	int ans = 0;
	Loop(i, 1, n)
	{
		cin >> a[i];
		ans += getNum(a[i - 1], a[i]);
	}
	if (inff)
		Kill("Infinite");
	Loop(i, 2, n)
	{
		if (a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2)
			ans--;
	}
	cout << "Finite\n";
	cout << ans << '\n';
}