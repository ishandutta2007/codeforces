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
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 5005;

ld f[maxn];
ld nf[maxn];
ld s[maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n, T;
	cin >> n >> T;
	
	f[0] = 1;
	ld ans = 0;
	
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < maxn; j++)
			nf[j] = 0;
			
		ld p;
		int ct;
		cin >> p >> ct;
		
		p /= 100.0;
		
		
		s[0] = f[0];
		for (int j = 1; j < maxn; j++)
			s[j] = s[j - 1] * (1.0 - p) + f[j];
			
		ld pw = 1.0;
		
		for (int j = 0; j < ct - 1; j++)
			pw *= 1.0 - p;
			
		for (int j = 1; j < maxn; j++)
		{
			ld x = s[j - 1];
			if (j - ct >= 0)
				x -= s[j - ct] * pw;
				
			x *= p;
			
			if (j - ct >= 0)
				x += pw * f[j - ct];
				
			nf[j] = x;
			
			if (j <= T)
				ans += x;
		}
		
		for (int j = 0; j < maxn; j++)
			f[j] = nf[j];
	}
	
	cout.precision(10);
	cout << fixed << ans << endl;
	
	
	return 0;
}