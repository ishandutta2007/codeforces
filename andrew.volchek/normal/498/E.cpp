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

struct matr
{
	int maxn;
	int n;
	
	ll a[1 << 7][1 << 7];
	
	matr(int _n)
	{
		maxn = 1 << _n;
		n = _n;
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				a[i][j] = 0;
	}
	
	matr operator * (const matr &other) const
	{
		matr res(n);
		
		ll mod2 = mod * mod;
		
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
			{
				for (int h = 0; h < maxn; h++)
				{
					res.a[i][j] += (a[i][h] * other.a[h][j]);
					if (res.a[i][j] >= mod2)
						res.a[i][j] -= mod2;
				}
				res.a[i][j] %= mod;
			}
		
		return res;
	}
	
	vector < ll > operator * (const vector < ll > &row)
	{
		vector < ll > res(maxn);
		
		for (int i = 0; i < maxn; i++)
		{
			for (int j = 0; j < maxn; j++)
			{
				res[i] += (a[i][j] * row[j]) % mod;
			}
			
			res[i] %= mod;
		}
		
		return res;
	}
};


matr gen(int n)
{
	if (n == 1)
	{
		matr res(n);
		res.a[0][1] = 1;
		res.a[0][0] = 1;
		res.a[1][0] = 1;
		return res;
	}
	
	matr res(7);
	
	for (int left = 0; left < (1 << n); left++)
	{
		for (int mid = 0; mid < (1 << (n - 1)); mid++)
		{
			int cmid = (mid << 1) | 1 | (1 << n);
			for (int right = 0; right < (1 << n); right++)
			{
				bool bad = false;
				for (int j = 0; j < n && !bad; j++)
				{
					bad |=
						bool(left & (1 << j)) &&
						bool(right & (1 << j)) &&
						bool(cmid & (1 << j)) &&
						bool(cmid & (1 << (j + 1)));
				}
				
				if (!bad)
				{
					res.a[right][left]++;
				}
			}
		}
	}
	
	return res;
}



int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	vector < ll > ans(1 << 7);
	ans[1] = 1;
	
	for (int i = 1; i <= 7; i++)
	{
		int n;
		cin >> n;
		
		matr x(7), res(7);
		
		x = gen(i);
		
		
		for (int j = 0; j < (1 << i); j++)
			for (int h = 0; h < (1 << i); h++)
				res.a[j][h] = j == h;
			
		while (n)
		{
			if (n & 1)
				res = res * x;
			
			x = x * x;
			n >>= 1;
		}
		
		ans = res * ans;
		
		if (i == 7)
			break;
		
		//ans.resize(ans.size() * 2);

		for (int j = 0; j < (1 << i); j++)
		{
			ans[j | (1 << i)] = ans[j];
			ans[j] = 0;
		}
	}
	
	cout << ans[(1 << 7) - 1] << endl;	
	
	return 0;
}