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

const int maxn = 1005;

ld cnt[maxn][maxn];
ld s[maxn];
ld fact[maxn];


int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i <= max(n, m); i++)	
		cnt[i][0] = cnt[i][i] = 1;
	for (int i = 1; i <= max(m, n); i++)
		for (int j = 1; j < i; j++)	
			cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1];
	
	
	ld ans = 0.0;
	
	for (int i = 1; i <= min(n, m); i++)
	{
		ld curr = 1;
		for (int j = m * n - m - (n - i) + 1; j <= m * n - m; j++)
			curr = curr * j / (j - (m * n - m - (n - i)));
	//	cerr << curr << endl;
		ans += cnt[m][i] * curr * n * ((ld)i / n) * ((ld)i / n);
	}
	
	for (int i = n * m - n + 1; i <= n * m; i++)
		ans = ans / i * (i - (n * m - n + 1) + 1);
		
	
	//cout <<  << endl;
	cout.precision(7);
	cout << fixed << ans << endl;
	
	return 0;
}