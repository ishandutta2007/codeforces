
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
//#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

char dp[11][1 << 9][1 << 9][10];
pair < void*, char > prv[11][1 << 9][1 << 9][10];

inline int bt(int x, int i)
{
	return bool(x & (1 << i));
}

inline void sb(int &x, int i, bool val)
{
	x = (x & (~(1 << i))) | ((1 << i) * val);
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n, m;
	cin >> n >> m;
	
	for (int p = 0; p <= m; p++)
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < (1 << n); j++)
				for (int k = 0; k <= n; k++)
					dp[p][i][j][k] = -100;
				
	dp[0][(1 << n) - 1][(1 << n) - 1][0] = 0;
	
	for (int i = 0; i < m; i++)
	{
		for (int p = 0; p < n; p++)
		{
			for (int msk1 = 0; msk1 < (1 << n); msk1++)
			{
				for (int msk2 = 0; msk2 < (1 << n); msk2++)
				{
					auto relax = [&](int m1, int m2, int addP, int addV, int type)
					{
						if (dp[i][m1][m2][p + addP] < dp[i][msk1][msk2][p] + addV)
						{
							dp[i][m1][m2][p + addP] = dp[i][msk1][msk2][p] + addV;
							prv[i][m1][m2][p + addP] = mp((void*)&prv[i][msk1][msk2][p], type);
						}
					};
					
					
					//###
					//.#.
					//.#.
					if (p + 2 < n)
					{
						if (!bt(msk1, p) && !bt(msk2, p) && !bt(msk2, p + 1) && !bt(msk2, p + 2))
						{							
							relax(
								msk1 ^ (1 << p),
								msk2 ^ (1 << p) ^ (1 << (p + 1)) ^ (1 << (p + 2)),
								+1,
								+1,
								1);
						}
					}
					
					//.#.
					//.#.
					//###
					if (p - 2 >= 0)
					{
						if (!bt(msk1, p) && !bt(msk2, p) && !bt(msk1, p - 1) && !bt(msk1, p - 2))
						{
							int nmsk1 = msk1, nmsk2 = msk2;
							sb(nmsk1, p, 1);
							sb(nmsk2, p, 1);
							sb(nmsk1, p - 1, 1);
							sb(nmsk1, p - 2, 1);
							relax(
								nmsk1,
								nmsk2,
								+1,
								+1,
								2
							);
						}
					}
					
					//#..<
					//###
					//#..
					if (p + 2 < n)
					{
						if (!bt(msk1, p) && !bt(msk1, p + 1) && !bt(msk2, p + 1) && !bt(msk1, p + 2))
						{
							int nmsk1 = msk1, nmsk2 = msk2;
							sb(nmsk1, p, bt(msk2, p));
							sb(nmsk2, p, 0);
							sb(nmsk1, p + 1, 1);
							sb(nmsk2, p + 1, 1);
							sb(nmsk1, p + 2, 1);
							relax(
								nmsk1,
								nmsk2,
								+2,
								+1,
								3
							);
						}
					}
					
					//..#
					//###
					//..#
					if (p + 2 < n)
					{
						if (!bt(msk1, p + 1) && !bt(msk2, p + 1))
						{
							int nmsk1 = msk1, nmsk2 = msk2;
							sb(nmsk1, p, bt(msk2, p));
							sb(nmsk2, p, 1);
							nmsk1 ^= (1 << (p + 1));
							nmsk2 ^= (1 << (p + 1));
							sb(nmsk1, p + 2, bt(msk2, p + 2));
							sb(nmsk2, p + 2, 1);
							
							relax(
								nmsk1,
								nmsk2,
								+3,
								+1,
								4);
						}
					}
					
					int nmsk1 = msk1, nmsk2 = msk2;
					sb(nmsk1, p, bt(nmsk2, p));
					sb(nmsk2, p, 0);
					
					relax(
						nmsk1,
						nmsk2,
						+1,
						0,
						5);
				}
			}
		}
		
		for (int msk1 = 0; msk1 < (1 << n); msk1++)
		{
			for (int msk2 = 0; msk2 < (1 << n); msk2++)
			{
				dp[i + 1][msk1][msk2][0] = dp[i][msk1][msk2][n];
				prv[i + 1][msk1][msk2][0] = mp((void*)&prv[i][msk1][msk2][n], 6);
			}
		}
	}
	
	int ansCost = 0;
	void *ptr = 0;
	int cm, cp;
	
	for (int msk1 = 0; msk1 < (1 << n); msk1++)
	{
		for (int msk2 = 0; msk2 < (1 << n); msk2++)
		{
			if (dp[m][msk1][msk2][0] > ansCost)
			{
				ansCost = dp[m][msk1][msk2][0];
				ptr = &prv[m][msk1][msk2][0];
				cm = m;
				cp = 0;
			}
		}
	}
	
	cout << ansCost << endl;
	
	vector < vector < char > > ans(n, vector < char > (m, '.'));
	
	int counter = 0;
	
	while (ptr)
	{
		char mark = 'A' + counter;
		int type = ((pair < void*, char >*)ptr)->snd;
		ptr = ((pair < void*, char >*)ptr)->fst;
		//cerr << cm << " " << cp << " " << type << endl;
		if (type == 1)
		{
			//###
			//.#.<
			//.#.
			ans[cp + 1][cm - 1] = mark;
			ans[cp][cm - 1] = mark;
			ans[cp - 1][cm] = ans[cp - 1][cm - 1] = ans[cp - 1][cm - 2] = mark;
			counter++;
			
			cp -= 1;
		}
		else if (type == 2)
		{
			//.#.
			//.#.
			//###
			//   <
			ans[cp - 3][cm - 1] = mark;
			ans[cp - 2][cm - 1] = mark;
			ans[cp - 1][cm] = ans[cp - 1][cm - 1] = ans[cp - 1][cm - 2] = mark;
			counter++;
			
			cp -= 1;
		}
		else if (type == 3)
		{
			//#..
			//###
			//#..<
			ans[cp][cm - 2] = mark;
			ans[cp - 1][cm] = ans[cp - 1][cm - 1] = ans[cp - 1][cm - 2] = mark;
			ans[cp - 2][cm - 2] = mark;
			counter++;
			
			cp -= 2;
		}
		else if (type == 4)
		{
			//..#
			//###
			//..#
			//   <
			ans[cp - 1][cm] = mark;
			ans[cp - 2][cm] = ans[cp - 2][cm - 1] = ans[cp - 2][cm - 2] = mark;
			ans[cp - 3][cm] = mark;
			counter++;
			
			cp -= 3;
		}
		else if (type == 5)
		{
			cp--;
		}
		else if (type == 6)
		{
			cm--;
			cp = n;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}

	return 0;
}