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

ld ans = 0;

int p[6];
int n;
ld mult;

void rec(int k)
{
	if (k == 0)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				cnt += p[i] > p[j];
		ans += cnt * mult;
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			reverse(p + i, p + j + 1);
			rec(k - 1);
			reverse(p + i, p + j + 1);
		}
	}
}


int main()
{
//	srand(time(NULL));
//	gen();
	//freopen("a.in", "r", stdin);
	
	int k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		cin >> p[i];
		
	mult = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			mult += 1;
	mult = 1.0 / mult;
	ld p  = 1;
	for (int i = 0; i < k ;i++)
		p *= mult;
	mult = p;
	
	rec(k);
	
	cout.precision(10);
	cout << fixed << ans << endl;
	
	

	return 0;
}