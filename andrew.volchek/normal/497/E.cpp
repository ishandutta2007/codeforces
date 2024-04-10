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

const ll mod = 1000000007;
const int maxn = 31;

int k;

struct matr
{
	ll a[maxn][maxn];
	
	matr()
	{
		for (int i = 0; i < k + 1; i++)
			for (int j = 0; j < k + 1; j++)
				a[i][j] = 0;
	}
	
	matr operator * (const matr &other) const
	{
		matr res;
		ll mod2 = mod * mod;
		
		for (int i = 0; i < k + 1; i++)
			for (int j = 0; j < k + 1; j++)
			{
				for (int h = 0; h < k + 1; h++)
				{
					res.a[i][j] += a[i][h] * other.a[h][j];
					if (res.a[i][j] >= mod2)
						res.a[i][j] -= mod2;
				}
				res.a[i][j] %= mod;
			}
			
		return res;
	}
};

map < pair < int, int >, matr > cache;

matr rot(const matr &x, int add)
{
	matr res;
	
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			res.a[(i + add) % k][(j + add) % k] = x.a[i][j];
			
	for (int i = 0; i < k; i++)
		res.a[(i + add) % k][k] = x.a[i][k];
		
	res.a[k][k] = 1;
	
	return res;
}


matr get(int n, int add)
{
	if (cache.find(mp(n, add)) != cache.end())
		return cache[mp(n, add)];
		
	matr res;
	
	if (n == 0)
	{
		if (add == 0)
		{
			for (int i = 0; i <= k; i++)
				res.a[0][i] = 1;
				
			for (int i = 1; i <= k; i++)
				res.a[i][i] = 1;
		}
		else
		{
			res = rot(get(n, add - 1), 1);
		}
		
		return cache[mp(n, add)] = res;
	}
	else
	{
		if (add == 0)
		{
			res = get(n - 1, 0);
			
			for (int i = 1; i < k; i++)
				res = get(n - 1, i) * res;
		}
		else
		{
			res = rot(get(n, add - 1), 1);
		}
		
		return cache[mp(n, add)] = res;
	}
}


int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	ll n;
	cin >> n >> k;
	
	matr ans;
	for (int i = 0; i < k + 1; i++)
		ans.a[i][i] = 1;
		
	int add = 0;
		
	while (n)
	{
		ll g = 1;
		int pw = 0;
		
		while (g <= (n / k + 5) && g * k <= n)
		{
			g *= k;
			pw++;
		}
		
		while (g <= n)
		{
			ans = get(pw, add % k) * ans;
			add++;
			n -= g;
		}
	}
	
	ll ans2 = 1;
	
	for (int i = 0; i < k; i++)
		ans2 = (ans2 + ans.a[i][k]) % mod;
		
	cout << ans2 << endl;
	
	return 0;
}