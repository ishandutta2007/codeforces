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

const int maxn = 1005;

int w[maxn], b[maxn];


int used[maxn];
int currUsed = 1;

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> w[i];
		
	vector < int > p;
	set < int > was;
		
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		if (was.count(b[i]) == 0)
		{
			was.insert(b[i]);
			p.pb(b[i]);
		}
	}
	
	reverse(p.begin(), p.end());
	
	for (int i = 0; i < m; i++)
		p.pb(b[i]);
		
	ll ans = 0;
	
	was.clear();
	
	for (int i = 0; i < p.size(); i++)
	{
		currUsed++;
		int x = p[i];
		
		if (was.count(x) == 0)
		{
			was.insert(x);
			continue;
		}
		
		int v = i - 1;
		while (p[v] != x)
		{
			if (used[p[v]] != currUsed)
			{
				used[p[v]] = currUsed;
				ans += w[p[v]];
			}
			v--;
		}
	}
	
	cout << ans << endl;

	
	return 0;
}