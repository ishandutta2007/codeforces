#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100000;
int a[N];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Loop(i, 0, n)
			cin >> a[i];
		sort(a, a + n);
		if (n & 1)
		{
			cout << a[n / 2] << ' ';
		}
		LoopR(i, 0, n / 2)
		{
			cout << a[i] << ' ' << a[n - i - 1] << ' ';
		}
		cout << '\n';
	}
}