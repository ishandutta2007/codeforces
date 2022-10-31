#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

vector < int > lines[305];

pair < ld, ld > intersect(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2)
{
	ld den = a1 * b2 - b1 * a2;
	
	pair < ld, ld > res;
	res.fst = -(c1 * b2 - b1 * c2) / den;
	res.snd = -(a1 * c2 - c1 * a2) / den;
	
	return res;
}

const ld eps = 1e-9;

void cut(vector < pair < ld, ld > > &points, pair < ld, ld > p1, pair < ld, ld > p2)
{
	ld a = (p1.snd - p2.snd);
	ld b = -(p1.fst - p2.fst);
	ld c = -a * p1.fst - b * p1.snd;	
	
	int prv = 0;
	int n = points.size();
	
	vector < pair < ld, ld > > ans;
	
	if (n == 0)
		return;
	
	for (int i = 0; i < n + 1; i++)
	{
		int curr;
		
		if (a * points[i % n].fst + b * points[i % n].snd + c > eps)
			curr = 1;
		else
			curr = -1;
			
		if (prv != 0 && prv != curr)
		{
			ld a2 = (points[i % n].snd - points[(i + n - 1) % n].snd);
			ld b2 = -(points[i % n].fst - points[(i + n - 1) % n].fst);
			ld c2 = -points[i % n].fst * a2 - points[i % n].snd * b2;
			
			ans.pb(intersect(a, b, c, a2, b2, c2));
		}
		
		if (curr == 1 && i != n)
			ans.pb(points[i]);
		
		prv = curr;
	}
	
	points = ans;
}

ld areas[305];

ld getArea(const vector < pair < ld, ld > > &points)
{
	ld res = 0;
	if (points.size())
	{
		int m = points.size();
		for (int h = 0; h < m; h++)
		{
			res += (points[(h+1) % m].fst - points[h % m].fst) *
				   (points[(h+1) % m].snd + points[h % m].snd) / 2.0;
		}
	}
	return abs(res);
}

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k + 1; j++)
		{
			int x;
			scanf("%d", &x);
			lines[i].pb(x);
		}
	}
	const ld inf = 2000;
	
	for (int i = 0; i < k; i++)
	{
		vector < pair < ld, ld > > points;
		points.pb(mp(i, 0));
		points.pb(mp(i, inf));
		points.pb(mp(i+1, inf));
		points.pb(mp(i+1, 0));
		ld prevArea = getArea(points);
		for (int j = 0; j < n; j++)
		{
			cut(points, mp(i, lines[j][i]), mp(i+1, lines[j][i+1]));
			areas[j] += prevArea - getArea(points);
			prevArea = getArea(points);			
		}
	}
	
	cout.precision(7);
	
	for (int i = 0; i < n; i++)
	{
		cout << fixed << areas[i] << endl;
	}
	
	return 0;
}