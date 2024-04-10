#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double



int main(int argc, char **argv)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	ull ans = 0;
	int curr = 1;
	
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		
		if (x >= curr)
		{
			ans += x - curr;
			curr = x;
		}
		else
		{
			ans += (n - curr) + x;
			curr = x;
		}
	}
	
	cout << ans;
	
	return 0;
}