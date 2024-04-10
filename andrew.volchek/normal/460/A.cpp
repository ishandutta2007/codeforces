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

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; ; i++)
	{
		if (!n)
		{
			cout << i - 1 << endl;
			return 0;
		}
		n--;
		if (i % m == 0)
			n++;
	}
	
	
	return 0;
}