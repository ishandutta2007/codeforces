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

const int N = 300010;
string a;
string b;
int n;

bool make(char x, char y)
{
	bool xf = 0, yf = 0;
	b.clear();
	for (auto c : a)
	{
		if (c == x || c == y)
			b.push_back(c);
		xf |= c == x;
		yf |= c == y;
	}
	return xf && yf;
}

int check2()
{
	int s;
	int n = b.size();
	Loop(i, 1, n)
	{
		if (b[i] != b[i - 1])
		{
			s = i;
			break;
		}
	}
	int ans = 0;
	Loop(i, s, s + n)
	{
		if (b[(i - 1) % n] == b[i % n])
			ans++;
	}
	return ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a;
		n = a.size();
		int ans = 0;
		Loop(i, 0, 10)
		{
			Loop(j, i, 10)
			{
				if (i == j)
				{
					make(i + '0', i + '0');
					ans = max(ans, (int)b.size());
				}
				else
				{
					if (make(i + '0', j + '0'))
						ans = max(ans, (int)b.size() - check2());
				}
			}
		}
		cout << n - ans << '\n';
	}
}