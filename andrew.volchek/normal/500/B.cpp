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
#include <unordered_map>
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

const int maxn = 305;
int used[maxn];

int p[maxn];
int a[maxn][maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", p + i);
		
	scanf("\n");
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char ch;
			scanf("%c", &ch);
			a[i][j] = ch == '1';
		}
		a[i][i] = 1;
		scanf("\n");
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				a[j][k] |= a[j][i] && a[i][k];
				
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
			
		int best = -1;
		
		for (int j = 0; j < n; j++)
		{
			if (!used[j] && a[i][j])
			{
				if (best == -1 || p[best] > p[j])
					best = j;
			}
		}
		
		used[best] = 1;
		cout << p[best];
	}
	
	
	return 0;
}