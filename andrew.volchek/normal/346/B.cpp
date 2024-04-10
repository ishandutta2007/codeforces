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

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

struct ans
{
	int i, j, k;
	char ch;
	ans(int _i, int _j, int _k, char _ch)
	{
		i = _i, j = _j, k = _k, ch = _ch;
	}
	ans()
	{
	}
};

const int maxn = 105;

string str[2];
string v;

int dp[maxn][maxn][maxn];
ans prv[maxn][maxn][maxn];

int lnk[maxn], nxt[maxn][26];

void norm(string &str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] -= 'A';
}

int main(int argc, char *argv[])
{
    //freopen("a.in", "r", stdin);
    
    cin >> str[0];
    cin.ignore();
    
    cin >> str[1];
    cin.ignore();
   
    cin >> v;
    
    norm(str[0]), norm(str[1]), norm(v);
    
    for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 26; j++)
			nxt[i][j] = -1;
	
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			for (int k = 0; k < maxn; k++)
				dp[i][j][k] = -1;
						
	nxt[0][v[0]] = 1;
	
	for (int i = 1; i <= v.size(); i++)
	{
		if (i == 1)
		{
			lnk[i] = 0;
		}
		else
		{
			int p = lnk[i - 1];
			while (p > 0)
			{
				if (nxt[p][v[i - 1]] != -1)
					break;
				p = lnk[p];
			}
			
			if (nxt[p][v[i - 1]] != -1)
				p++;
				
			lnk[i] = p;
		}
		
		if (i < v.size())
		{
			nxt[i][v[i]] = i + 1;
		}
		
		for (int j = 0; j < 26; j++)
		{
			if (nxt[i][j] == -1)
				nxt[i][j] = nxt[lnk[i]][j];
		}
	}
	
	for (int i = 0; i <= v.size(); i++)
		for (int j = 0; j < 26; j++)
			if (nxt[i][j] == -1)
				nxt[i][j] = 0;

	dp[0][0][0] = 0;
	
	for (int i = 0; i < str[0].size(); i++)
	{
		for (int j = 0; j < str[1].size(); j++)
		{
			for (int k = 0; k < v.size(); k++)
			{
				if (dp[i][j][k] == -1)
					continue;
					
				if (dp[i + 1][j][k] < dp[i][j][k])
				{
					dp[i + 1][j][k] = dp[i][j][k];
					prv[i + 1][j][k] = ans(i, j, k, 27);
				}
				
				if (dp[i][j + 1][k] < dp[i][j][k])
				{
					dp[i][j + 1][k] = dp[i][j][k];
					prv[i][j + 1][k] = ans(i, j, k, 27);
				}
				
				if (dp[i + 1][j + 1][k] < dp[i][j][k])
				{
					dp[i + 1][j + 1][k] = dp[i][j][k];
					prv[i + 1][j + 1][k] = ans(i, j, k, 27);
				}
				
				if (str[0][i] == str[1][j] && dp[i + 1][j + 1][nxt[k][str[0][i]]] < dp[i][j][k] + 1)
				{
					dp[i + 1][j + 1][nxt[k][str[0][i]]] = dp[i][j][k] + 1;
					prv[i + 1][j + 1][nxt[k][str[0][i]]] = ans(i, j, k, str[0][i]);
				}
			}
		}
	}
	
	int x, y, z;
	int len = -1;
	
	for (int i = 0; i <= str[0].size(); i++)
		for (int j = 0; j <= str[1].size(); j++)
			for (int k = 0; k < v.size(); k++)
			{	
				if (dp[i][j][k] > len)
				{
					len = dp[i][j][k];
					x = i, y = j, z = k;
				}
			}
					
	if (len == 0)
	{
		cout << 0 << endl;
		return 0;
	}
				
	string ansS;
		
	while (true)
	{
		if (x == 0 && y == 0)
			break;
			
		if (prv[x][y][z].ch != 27)
			ansS += prv[x][y][z].ch + 'A';
			
		ans t = prv[x][y][z];
		x = t.i;
		y = t.j;
		z = t.k;
	}
	
	reverse(ansS.begin(), ansS.end());
	
	cout << ansS << endl;
	
	return 0;
}