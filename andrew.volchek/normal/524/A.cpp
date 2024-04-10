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



int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	int n, k;
	cin >> n >> k;
	
	map < int, set < int > > a;
	
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].insert(v);
		a[v].insert(u);
	}
	
	map < int, vector < int > > ans;
	
	for (auto kv : a)
	{
		for (auto vk : a)
		{
			if (vk.fst == kv.fst || kv.snd.count(vk.fst))
				continue;
				
			int cnt = 0;
			for (int x : kv.snd)
			{
				cnt += vk.snd.count(x);
			}
			
			if (cnt * 100 >= k * kv.snd.size())
			{
				ans[kv.fst].pb(vk.fst);
			}
		}
	}
	
	for (auto vk : a)
	{
		auto b = ans[vk.fst];
		printf("%d: %d", vk.fst, (int)b.size());
		for (int y : b)
			printf(" %d", y);
		printf("\n");
	}

	return 0;
}