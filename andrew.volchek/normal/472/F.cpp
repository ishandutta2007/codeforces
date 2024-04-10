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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}


const int maxn = 10005;

int a[maxn], b[maxn], c[maxn];
int was[maxn];
int currUsed = 1;

void f(int *a, int n, vector < pair < int, int > > &op, vector < int > &p)
{
	for (int i = 31; i >= 0; i--)
	{
		int j = 0;
		while (j < n && ((a[j] & (1 << i)) == 0 || was[j] == currUsed)) j++;
		
		if (j == n)
			continue;
			
		p[i] = j;
		was[j] = currUsed;
		
		for (int h = 0; h < n; h++)
		{
			if ((a[h] & (1 << i)) == 0 || was[h] == currUsed)
				continue;
				
			a[h] ^= a[j];
			op.pb(mp(h, j));
		}
	}
}

int main()
{
	//gen();
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		c[i] = b[i];
	}
	
	vector < int > p(32, -1);
	vector < int > p2(32, -1);
	vector < pair < int, int > > op;
	vector < pair < int, int > > op2;
	
	f(a, n, op, p);
	currUsed++;
	f(b, n, op2, p2);
	currUsed++;
	
	for (int i1 = 31; i1 >= 0; i1--)
	{
		if (p2[i1] == -1)
		{
			continue;
		}
			
		if (p[i1] == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		else if (p[i1] != p2[i1])
		{
			a[p[i1]] ^= a[p2[i1]];
			a[p2[i1]] ^= a[p[i1]];
			a[p[i1]] ^= a[p2[i1]];
			op.pb(mp(p[i1], p2[i1]));
			op.pb(mp(p2[i1], p[i1]));
			op.pb(mp(p[i1], p2[i1]));
			int prv = p[i1];
			for (int &y : p)
				if (y == p2[i1])
					y = prv;
			p[i1] = p2[i1];
		}
		
		
		for (int i2 = 31; i2 >= 0; i2--)
		{
			if (i2 == i1)
				continue;
				
			if (p[i2] == -1)
				continue;
				
			if (bool(a[p[i1]] & (1 << i2)) != bool(b[p[i1]] & (1 << i2)))
			{
				a[p[i1]] ^= a[p[i2]];
				op.pb(mp(p[i1], p[i2]));
			}
		}
		
		was[p[i1]] = currUsed;
		
		if (b[p[i1]] != a[p[i1]])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (was[i] == currUsed)
			continue;
		a[i] ^= a[i];
		op.pb(mp(i, i));
		
		for (int j = 31; j >= 0; j--)
		{
			if (p[j] == -1 || was[p[j]] != currUsed)
				continue;
				
			if (bool(c[i] & (1 << j)) != bool(a[i] & (1 << j)))
			{
				a[i] ^= a[p[j]];
				op.pb(mp(i, p[j]));
			}
		}
		
		if (a[i] != c[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	
	for (int i = (int)op2.size() - 1; i >= 0; i--)
	{
		if (was[op2[i].fst] != currUsed || was[op2[i].snd] != currUsed)
			continue;
		op.pb(op2[i]);
		a[op2[i].fst] ^= a[op2[i].snd];
	}
	
	for (int i = 0; i < n; i++)
		assert(a[i] == c[i]);
	
	
	printf("%d\n", op.size());
	for (pair < int, int > x : op)
		printf("%d %d\n", x.fst + 1, x.snd + 1);
	
    return 0;
}