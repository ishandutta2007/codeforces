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

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

int main()
{
	//freopen("a.in", "r", stdin);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	
	int res = 1e9;
	res = min(res, a / 1);
	res = min(res, b / 1);
	res = min(res, c / 2);
	res = min(res, d / 7);
	res = min(res, e / 4);
	
	cout << res;
	

	return 0;
}