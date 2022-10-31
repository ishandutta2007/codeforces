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

const int maxn = 300005;
const ll mod = 1000000007;

char s[maxn], t[maxn];
int pr[maxn];

ll tr[maxn];

void add(int i, ll x)
{
	while (i < maxn)
	{
		tr[i] += x;
		if (tr[i] >= mod)
			tr[i] -= mod;
		i = i | (i + 1);
	}
}

ll sum(ll r)
{
	ll res = 0;
	while (r >= 0)
	{
		res += tr[r];
		if (res >= mod)
			res -= mod;
		r = (r & (r + 1)) - 1;
	}
	return res;
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	gets(s);
	gets(t);
	
	string x = string(t) + "$" + string(s);
	
	for (int i = 1; i < x.size(); i++)
	{
		int j = pr[i - 1];
		while (j > 0 && x[i] != x[j])
			j = pr[j - 1];
		if (x[i] == x[j])
			j++;
		pr[i] = j;
	}
	
	
	
	
	int pos = -1;
	
	int len = strlen(t);
	
	add(len, 1);
	
	ll ans = 0;
	ll prv = 1;
	
	for (int i = len + 1; i < x.size(); i++)
	{
		if (pr[i] >= len)
			pos = i;
			
		ll res = 0;
		if (pos != -1)
		{
			res = sum(pos - len);
			res = (res + prv) % mod;
			ans += res;
		}
		else
			res = prv;
		
			
		add(i, (res));
		prv = res;
	}
	
	
	cout << (prv - 1 + mod) % mod << endl;
	
	
	return 0;
}