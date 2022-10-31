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



int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int a[6];
	int p[6] = { 0, 1, 2, 3, 4, 5 };
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
	}
	do {
		bool all = true;
		for (int i = 0; i < 3; i++)
			all &= a[p[i]] == a[p[i + 1]];
		if (!all)
			continue;
		if (a[p[4]] > a[p[5]])
		{
			cout << "Bear" ;
			return 0;
		}
		else if (a[p[4]] == a[p[5]])
		{
			cout << "Elephant";
			return 0;
		}
	} while (next_permutation(p, p + 6));
	cout << "Alien" << endl;
	return 0;
}