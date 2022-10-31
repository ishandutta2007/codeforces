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

int a[105][105];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	int u = 0;
	int cnt = 0;
	
	for (int i = 0; i < 100 && n; i++)
	{
		cnt++;
		if (u * (u - 1) / 2 <= n)
		{
			for (int j = 0; j < u; j++)
			{
				a[j][i] = a[i][j] = 1;
			}
			n -= u * (u - 1) / 2;
			u++;
		}
		else
		{
			int x = 0;
			while (x <= u && x * (x - 1) / 2 <= n) x++;
			x--;
			
			for (int j = 0; j < x; j++)
				a[j][i] = a[i][j] = 1;
			
			n -= x * (x - 1) / 2;
		}
	}
	
	assert(n == 0);
	
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	
	return 0;
}