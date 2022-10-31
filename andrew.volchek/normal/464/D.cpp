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
#include <ctime>
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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxk = 1800;

ld a[maxk];
ld b[maxk];
ld inv[maxk + 1];
ld c[maxk];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, k;
	cin >> n >> k;

	a[1] = k;
	
	ld ans = 0;
	for (int j = 1; j < maxk; j++)
		inv[j] = 1.0 / k / j, c[j] = (1.0 / k) * ((ld)j * (j + 1) / 2 / (j + 1) + (ld)j / (j + 1));
	
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 1; j < maxk; j++)
		{

			b[j] = a[j] * (1.0 - inv[j + 1]) + a[j - 1] * inv[j];
		}
		
		for (int j = 1; j < maxk; j++)
		{
				
			ans += a[j] * c[j];
			a[j] = b[j];
			
			if (a[j] < 1e-50)
				a[j] = 0;
		}
		
		
	//for (int j = 0; j < maxk; j++)
		//	a[j] /= sum;
	}
	
	cerr << a[50] << endl;
	
	cout.precision(11);
	cout << fixed << ans;
	
	return 0;
}