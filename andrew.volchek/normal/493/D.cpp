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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}


void relax(pair < ll, ll > &ans, pair < ll, ll > curr)
{
	if (curr.fst - curr.snd > ans.fst - ans.snd)
		ans = curr;
	else if (curr.fst - curr.snd == ans.fst - ans.snd)
	{
		if (curr.fst > ans.fst)
			ans = curr;
	}
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << "white" << endl << 1 << " " << 2 << endl;
	else
		cout << "black" << endl;

	return 0;
}