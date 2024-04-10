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
#include <functional>

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


const int maxn = 105;

ld f[maxn][maxn][maxn];


int main()
{
	srand(time(NULL));
	//gen();
	
	int a, b, c;
	cin >> a >> b >> c;
	
	f[a][b][c] = 1;
	
	for (int i = maxn - 1; i >= 0; i--) // stone
	{
		for (int j = maxn - 1; j >= 0; j--) // scissors
		{
			for (int k = maxn - 1; k >= 0; k--) // papers
			{
				ld s = i + j + k;
				s = i * j + j * k + i * k;
				
				if (i && j)
					f[i][j - 1][k] += f[i][j][k] * (i * j) / s;
					
				if (j && k)
					f[i][j][k - 1] += f[i][j][k] * (j * k) / s;
					
				if (k && i)
					f[i - 1][j][k] += f[i][j][k] * (i * k) / s;
			}
		}
	}
	
	cout.precision(10);
	
	ld ans = 0;
	for (int i = 1; i < maxn; i++)
		ans += f[i][0][0];
		
	cout << fixed << ans;
	
	ans = 0;
	for (int i = 1; i < maxn; i++)
		ans += f[0][i][0];
		
	cout << " " << fixed << ans;
	
	ans = 0;
	for (int i = 1; i < maxn; i++)
		ans += f[0][0][i];
		
	cout << " " << fixed << ans;
		
	return 0;
}