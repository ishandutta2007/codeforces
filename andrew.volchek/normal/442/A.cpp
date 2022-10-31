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

pair < int, int > a[105];



int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++)
	{
		char c1, c2;
		scanf("%c%c ", &c2, &c1);
		a[i].fst = c1 - '1';
		
		if (c2 == 'R')
			a[i].snd = 0;
		else if (c2 == 'G')
			a[i].snd = 1;
		else if (c2 == 'B')
			a[i].snd = 2;
		else if (c2 == 'Y')
			a[i].snd = 3;
		else
			a[i].snd = 4;
	}
	
	sort(a, a + n);
	n = unique(a, a + n) - a;
	
//	for (int i = 0; i < n; i++)
//		cerr << a[i].fst << " " << a[i].snd << endl;
	
	set < pair < int, int > > s;
	
	int ans = 100;
	
	for (int i = 0; i < (1 << 10); i++)
	{
		s.clear();
		
		for (int j = 0; j < n; j++)
		{
			pair < int, int > curr = mp(-1, -1);
			if (i & (1 << a[j].fst))
				curr.fst = a[j].fst;
			if (i & (1 << (5 + a[j].snd)))
				curr.snd = a[j].snd;
			s.insert(curr);
		}
		
		
		if (s.size() == n)
		{
			//cerr << i << endl;
			int curr = 0;
			for (int j = 0; j < 11; j++)
				if (i & (1 << j))
					curr++;
			ans = min(ans, curr);
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}