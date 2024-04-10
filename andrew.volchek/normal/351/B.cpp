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

const int maxn = 4005;

int a[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	while (true)
	{
		bool any = false;
		for (int i = 0; i + 1 < n; i++)
		{
			if (a[i] > a[i + 1])
			{
				cnt++;
				any = true;
				swap(a[i], a[i + 1]);
			}
		}
		if (!any)
			break;
	}
	cout << cnt / 2 * 4 + (cnt & 1);
	return 0;
}