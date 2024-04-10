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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 500010;
const int MAX = 10010;
pii ans[N];
int a[N];
int n;

vector<int> P;

bool isPrime(int x)
{
	if (x < 2)
		return false;
	if (x % 2 == 0)
		return x == 2;
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

pii Solve(int x)
{
	int a = 1;
	for (int i = 0; P[i]*P[i] <= x; ++i)
	{
		if (x % P[i])
			continue;
		while (x % P[i] == 0)
		{
			x /= P[i];
			a *= P[i];
		}
		break;
	}
	if (x == 1 || a == 1)
		return { -1,-1 };
	return { a, x };
}

int main()
{
	FAST;
	Loop(i, 2, MAX)
		if (isPrime(i))
			P.push_back(i);
	cin >> n;
	Loop(i, 0, n)
	{
		cin >> a[i];
		ans[i] = Solve(a[i]);
	}
	Loop(i, 0, n)
		cout << ans[i].first << ' ';
	cout << '\n';
	Loop(i, 0, n)
		cout << ans[i].second << ' ';
}