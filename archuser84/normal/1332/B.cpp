#define _CRT_SECURE_NO_WARNINGS
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

const int N = 1000;
int a[N];
int c[N];
bool ced[N];
int n;
int m;

const int P[] = { 2,3,5,7,11,13,17,19,23,29,31 };

void Color()
{
	m = 0;
	memset(ced, 0, n);
	for(int p : P)
	{
		bool used = 0;
		Loop(i, 0, n)
		{
			if (a[i] % p == 0 && !ced[i])
			{
				ced[i] = true;
				c[i] = m + 1;
				used = true;
			}
		}
		if (used)
			m++;
	}
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Loop(i, 0, n)
		{
			cin >> a[i];
		}
		Color();
		cout << m << '\n';
		Loop(i, 0, n)
		{
			cout << c[i] << ' ';
		}
		cout << '\n';
	}
}