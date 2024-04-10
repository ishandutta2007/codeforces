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
#include <functional>

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

const int maxn = 200000 * 32 * 23;
bitset < maxn > used;

int n, m;

int a[30], b[30];
int blkCnt[1 << 5];


vector < int > curr;
int k[6];

void rec(int pos)
{
	if (pos == m + 1)
	{
		bool good = true;
		for (int i = 0; i < n; i++)
			good &= k[i] == a[i];
			
		if (good)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					printf("%c", bool(curr[j] & (1 << i)) ? '*' : '.');
				}
				printf("\n");
			}
			
			exit(0);
		}
		
		return;
	}
	
	//for (int i = 0; i < n; i++)
	//	if (k[i] > a[i])
	//		return;
	
	int v = 0;
	for (int i = 0; i < n; i++)
		v = v * 11 + k[i];
	v = v * (m + 2) + pos;
	v = (v << 5) + curr.back();
	
	if (used[v])
		return;
		
	used[v] = 1;
	
	
	for (int msk = 0; msk < (1 << n); msk++)
	{
		if (blkCnt[msk] != b[pos])
			continue;
		
		int prvMsk = curr.back();
		
		for (int j = 0; j < n; j++)
			if (!bool(prvMsk & (1 << j)) && bool(msk & (1 << j)))
				k[j]++;
				
		curr.pb(msk);
		rec(pos + 1);
		curr.pop_back();
		
		for (int j = 0; j < n; j++)
			if (!bool(prvMsk & (1 << j)) && bool(msk & (1 << j)))
				k[j]--;
	}
}


int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	for (int j = 1; j <= m; j++)
		cin >> b[j];
		
		
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (bool(i & (1 << j)) && (!j || !bool(i & (1 << (j - 1)))))
				blkCnt[i]++;
		}
	}
		
	curr.pb(0);
	rec(1);
	
	
	return 0;
}