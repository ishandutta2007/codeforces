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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;

ll a[maxn];
char str[maxn];

int main(int argc, char *argv[])
{
	gets(str);
	int len = strlen(str);
	
	
	for (int i = len - 1, j = 0; i >= 0; i--, j++)
		a[j] += str[i] - '0';
		
	gets(str);
	len = strlen(str);
	
	for (int i = len - 1, j = 0; i >= 0; i--, j++)
		a[j] -= str[i] - '0';
		
	for (int i = maxn - 1; i >= 2; i--)
	{
		if (a[i]  < -1000)
		{
			cout << "<";
			return 0;
		}
		
		if (a[i] > 1000)
		{
			cout << ">";
			return 0;
		}
		
		a[i - 1] += a[i];
		a[i - 2] += a[i];
	}
	
	const ld eps = 1e-7;
	
	
	if (1.618033988 * a[1] + a[0] > eps)
	{
		cout << ">";
	}
	else if (1.618033988 * a[1] + a[0] < -eps)
	{
		cout << "<";
	}
	else
	{
		cout << "=";
	}
	
	return 0;
}