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

const int maxn = 1 << 13;

int a[maxn];
int b[maxn];

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	for (int i = 0; i < maxn; i++)
		b[i] = -1;
	
	int n;
	scanf("%d", &n);
	
	for (int i = 2; i <= (1 << (n + 1)) - 1; i++)
	{
		scanf("%d", a + i);
	}
	
	ll ans = 0;
	
	for (int i = (1 << (n + 1)); i >= 2; i--)
	{
		if (b[i] == -1)
			b[i] = 0;
		int c = b[i] + a[i];
		if (b[i / 2] == -1)
			b[i / 2] = c;
		else
		{
			ans += abs(b[i / 2] - c);
			b[i / 2] = max(b[i / 2], c);
		}
	}
	
	cout << ans << endl;
	

	return 0;
}