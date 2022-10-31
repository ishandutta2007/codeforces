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

int a[3][15000005];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int k;
	int n[3], t[3];
	
	cin >> k;
	for (int i = 0; i < 3; i++)
		cin >> n[i];
	for (int i = 0; i < 3; i++)
		cin >> t[i];
		
	int ans = 0;
	int currT = 0;
	while (k)
	{
		while (a[0][currT] >= n[0] || a[1][currT + t[0]] >= n[1] || a[2][currT + t[0] + t[1]] >= n[2])
		{
			while (a[0][currT] >= n[0])
			{
				currT++;
			}
			
			while (a[1][currT + t[0]] >= n[1])
			{
				currT++;
				continue;
			}
			
			while (a[2][currT + t[0] + t[1]] >= n[2])
			{
				currT++;
			}
		}
		
		int g = currT;
		k--;
		//cerr << g << endl;
		ans = max(ans, currT + t[0] + t[1] + t[2]);
		for (int i = 0; i < t[0]; i++)
			a[0][currT + i]++;
		currT += t[0];
		for (int i = 0; i < t[1]; i++)
			a[1][currT + i]++;
		currT += t[1];
		for (int i = 0; i < t[2]; i++)
			a[2][currT + i]++;
		currT = g;
	}
	
	cout << ans << endl;
	

	return 0;
}