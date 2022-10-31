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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

char s[10000];
pair < string, string > a[100005];
int p[100005];

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		gets(s);
		int len = strlen(s);
		int j = 0;
		while (s[j] != ' ') j++;
		s[j] = 0;
		a[i].fst = string(s);
		a[i].snd = string(s + j + 1);
	}
	
	for (int i = 0; i < n; i++)
		scanf("%d", p + i);
		
	int can[2] = { 1, 1 };
	
	for (int i = 0; i + 1 < n; i++)
	{
		int u = p[i];
		int v = p[i + 1];
		int c1 = 0;
		int c2 = 0;
		
		if (can[0] && a[u].fst < a[v].fst)
			c1 = 1;
		if (can[0] && a[u].fst < a[v].snd)
			c2 = 1;
		if (can[1] && a[u].snd < a[v].fst)
			c1 = 1;
		if (can[1] && a[u].snd < a[v].snd)
			c2 = 1;
		can[0] = c1;
		can[1] = c2;
	}
	
	if (!can[0] && !can[1])
		puts("NO");
	else
		puts("YES");
	
	return 0;
}