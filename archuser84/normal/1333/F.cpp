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

const int N = 500010;

bool isPrime(int x)
{
	if (x < 2)
		return 0;
	if (x % 2 == 0)
		return x == 2;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return 0;
	return 1;
}

int Do(int x)
{
	if (x < 2)
		return -1;
	if (x % 2 == 0)
		return 2;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return i;
	return x;
}

int ans[N];
int n;

int main()
{
	FAST;
	cin >> n;
	Loop(i, 2, n + 1)
		ans[i] = i / Do(i);
	sort(ans + 2, ans + n + 1);
	Loop(i, 2, n + 1)
		cout << ans[i] << ' ';
}