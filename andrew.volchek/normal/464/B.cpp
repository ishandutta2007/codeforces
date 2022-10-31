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
#include <unordered_map>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

ll a[8][3];
int p[8][3];

void rec(int k)
{
	if (k == -1)
	{
		ll mm = 1e18;
		
		for (int i = 0; i < 8; i++)
			for (int j = i + 1; j < 8; j++)
			{
				ll curr = 0;
				for (int h = 0; h < 3; h++)
				{
					ll x = a[i][p[i][h]] - a[j][p[j][h]];
					curr += x * x;
				}
				mm = min(mm, curr);
			}
			
		if (mm == 0)
			return;
			
		ll m1 = 0, m2 = 0, m3 = 0;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = i + 1; j < 8; j++)
			{
				ll curr = 0;
				for (int h = 0; h < 3; h++)
				{
					ll x = a[i][p[i][h]] - a[j][p[j][h]];
					curr += x * x;
				}
				
				if (curr == mm)
				{
					m1++;
				}
				else if (curr == 2LL * mm)
					m2++;
				else if (curr == 3LL * mm)
					m3++;
				else
					return;
					
				if (m1 > 12)
					return;
				if (m2 > 12)
					return;
				if (m3 > 4)
					return;
			}
		}
		
		if (m1 == 12 && m2 == 12 && m3 == 4)
		{
			puts("YES");
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (j)
						cout << " ";
					cout << a[i][p[i][j]];
				}
				cout << endl;
			}
			exit(0);
		}
		
		return;
	}
	
	for (int i = 0; i < 3; i++)
		p[k][i] = i;
		
	do {
		rec(k - 1);
	} while (next_permutation(p[k], p[k] + 3));
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	rec(7);
	puts("NO");
	return 0;
}