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

string a[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};


char str[200];
int cnt = 8;
int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d\n", &n);
	
	gets(str);
	
	for (int i = 0; i < cnt; i++)
	{
		if (n != a[i].size())
			continue;
			
		bool good = true;
		
		for (int j = 0; j < n; j++)
			good &= a[i][j] == str[j] || str[j] == '.';
			
		if (good)
		{
			cout << a[i];
			return 0;
		}
	}
	
	return 0;
}