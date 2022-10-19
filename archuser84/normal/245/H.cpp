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

const int N = 5010;

char s[N];
int polin[N][N] = {};
bool is[N][N];

int main()
{
	FAST;
	cin >> s;
	int n = strlen(s);
	Loop(i, 0, n)
	{
		polin[i][i] = 1;
		is[i][i] = 1;
	}
	Loop(i, 0, n - 1)
	{
		polin[i][i + 1] = 2 + (s[i] == s[i + 1]);
		is[i][i + 1] = s[i] == s[i + 1];
	}
	Loop(j, 2, n)
	{
		Loop(i, 0, n - j)
		{
			is[i][i + j] = s[i] == s[i + j] && is[i + 1][i + j - 1];
			polin[i][i + j] = polin[i + 1][i + j] + polin[i][i + j - 1] - polin[i + 1][i + j - 1] + is[i][i+j];
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << polin[l][r] << '\n';
	}
}