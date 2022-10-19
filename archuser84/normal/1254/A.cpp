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

const int N = 110;

char ans[N][N];
bool grid[N][N];
int r, c;
int k;
int cnt;

char getC(int x)
{
	if (x < 10)
		return '0' + x;
	else if (x < 36)
		return 'a' + (x - 10);
	else
		return 'A' + (x - 36);
}
pair<int, int> getuv(int x)
{
	int u = x / c;
	int v = x % c;
	if (u & 1)
		v = c - v - 1;
	return { u,v };
}

void Input()
{
	cin >> r >> c >> k;
	cnt = 0;
	Loop(i, 0, r)
	{
		char t[N];
		cin >> t;
		Loop(j, 0, c)
		{
			grid[i][j] = t[j] == 'R';
			cnt += grid[i][j];
		}
	}
	Loop(i, 0, N)
		Loop(j, 0, N)
			ans[i][j] = 0;
}

void Solve()
{
	int x = cnt / k;
	int rem = cnt % k;
	int chick = 0;
	int rice = 0;
	Loop(i, 0, r * c)
	{
		pair<int, int> temp = getuv(i);
		int u = temp.first;
		int v = temp.second;
		ans[u][v] = getC(chick);
		if (grid[u][v])
		{
			rice++;
			if ((chick >= rem && rice == x) || rice == x + 1)
			{
				rice = 0;
				chick++;
				if (chick == k)
					chick--;
			}
		}
	}
}

void Output()
{
	Loop(i, 0, r)
		cout << ans[i] << '\n';
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Input();
		Solve();
		Output();
	}
}