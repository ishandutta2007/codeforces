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

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

int r[105], c[105];
int ri[105], ci[105];
int a[105][105];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			r[i] += x;
			c[j] += x;
			a[i][j] = x;
		}
	}
	
	queue < pair < int, int > > q;
	
	for (int i = 0; i < n; i++)
		if (r[i] < 0)
			q.push(mp(0, i));
	
	for (int i = 0; i < m; i++)
		if (c[i] < 0)
			q.push(mp(1, i));
			
	while (!q.empty())
	{
		pair < int, int > curr = q.front();
		q.pop();
		
		if (!curr.fst && r[curr.snd] >= 0)
			continue;
		else if (curr.fst && c[curr.snd] >= 0)
			continue;
			
		if (!curr.fst)
		{
			ri[curr.snd] ^= 1;
			r[curr.snd] = -r[curr.snd];
			for (int i = 0; i < m; i++)
			{
				c[i] -= a[curr.snd][i] * 2;
				a[curr.snd][i] = -a[curr.snd][i];
				if (c[i] < 0)
					q.push(mp(1, i));
			}
		}
		else
		{
			ci[curr.snd] ^= 1;
			c[curr.snd] = -c[curr.snd];
			for (int i = 0; i < n; i++)
			{
				r[i] -= a[i][curr.snd] * 2;
				a[i][curr.snd] = -a[i][curr.snd];
				if (r[i] < 0)
					q.push(mp(0, i));
			}
		}
	}
	

	vector < int > ra, ca;
	for (int i = 0; i < n; i++)
		if (ri[i])
			ra.pb(i + 1);
	for (int i = 0; i < m; i++)
		if (ci[i])
			ca.pb(i + 1);
			
	cout << ra.size();
	for (int i = 0; i < ra.size(); i++)
		cout << " " << ra[i];
	cout << endl;
	
	cout << ca.size();
	for (int i = 0; i < ca.size(); i++)
		cout << " " << ca[i];
	cout << endl;
	
	return 0;
}