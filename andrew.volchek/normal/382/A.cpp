#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

char str[1000];


int main()
{
	//freopen("a.in", "r", stdin);
	
	gets(str);
	int len = strlen(str);
	vector < char > l, r;
	int pos = 0;
	while (pos < len)
	{
		if (str[pos] == '|')
		{
			pos++;
			break;
		}
		l.pb(str[pos]);
		pos++;
	}
	while (pos < len)
	{
		r.pb(str[pos]);
		pos++;
	}
	
	gets(str);
	len = strlen(str);
	
	int b = l.size() + r.size() + len;
	if (b & 1)
	{
		puts("Impossible");
		return 0;
	}
	b /= 2;
	
	for (int i = 0; i < len; i++)
	{
		if (l.size() < b)
			l.pb(str[i]);
		else
			r.pb(str[i]);
	}
	
	if (l.size() != r.size())
		puts("Impossible");
	else
	{
		for (int i = 0; i < l.size(); i++)
			printf("%c", l[i]);
		printf("|");
		for (int i = 0; i < r.size(); i++)
			printf("%c", r[i]);
	}
	
	
	return 0;
}