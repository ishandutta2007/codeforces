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

const int N = 502;
char s[N][N];
int n, m;
vector<vector<unsigned int>> dp[N];
vector<vector<bool>> did[N];

unsigned int Solve(int si, int sj, int ti, int tj)
{
	if (si > ti || sj > tj)
		return 0;
	if (si + sj == ti + tj)
		return si == ti && sj == tj;
	if ((si + 1 == ti && sj == tj) || (si == ti && sj + 1 == tj))
		return s[si][sj] == s[ti][tj];
	if (did[si][sj][m - tj - 1])
		return dp[si][sj][m - tj - 1];
	dp[si][sj][m - tj - 1] = 0;
	did[si][sj][m - tj - 1] = 1;

	if (s[si][sj] == s[ti][tj])
	{
		dp[si][sj][m - tj - 1] += Solve(si + 1, sj, ti, tj - 1);
		dp[si][sj][m - tj - 1] %= Mod1;
		dp[si][sj][m - tj - 1] += Solve(si + 1, sj, ti - 1, tj);
		dp[si][sj][m - tj - 1] %= Mod1;
		dp[si][sj][m - tj - 1] += Solve(si, sj + 1, ti, tj - 1);
		dp[si][sj][m - tj - 1] %= Mod1;
		dp[si][sj][m - tj - 1] += Solve(si, sj + 1, ti - 1, tj);
		dp[si][sj][m - tj - 1] %= Mod1;
	}
	return dp[si][sj][m - tj - 1];
}

void Input()
{
	cin >> n >> m;
	Loop(i, 0, n)
		cin >> s[i];
	Loop(i, 0, N)
	{
		dp[i].resize(N - i - 1);
		did[i].resize(N - i - 1);
	}
	Loop(i, 0, N)
		Loop(j, 0, N)
			if (i + j < N - 1)
			{
				dp[i][j].resize(i + j + 1);
				did[i][j].resize(i + j + 1);
			}
}

int main()
{
	FAST;
	Input();
	cout << Solve(0, 0, n - 1, m - 1);
}