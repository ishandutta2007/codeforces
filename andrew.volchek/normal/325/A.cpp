#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

pair < int, int > a[15];
vector < int > x;
vector < int > y;
map < int, int > mx;
map < int, int > my;
int b[200][200];

int main(int argc, char **argv)
{
	int n;
	int xmin=100000, xmax=-1, ymin=100000, ymax=-1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i*2].fst = min(x1, x2);
		a[i*2].snd = min(y1, y2);
		a[i*2+1].fst = max(x1, x2);
		a[i*2+1].snd = max(y1, y2);
		xmin = min(xmin, x1);
		xmax = max(xmax, x2);
		ymin = min(ymin, y1);
		ymax = max(ymax, y2);
		x.pb(x1);
		x.pb(x2);
		x.pb(x1+1);
		x.pb(x2+1);
		x.pb(x1-1);
		x.pb(x2-1);
		y.pb(y1);
		y.pb(y2);
		y.pb(y1+1);
		y.pb(y2+1);
		y.pb(y1-1);
		y.pb(y2-1);
	}
	
	sort(x.begin(), x.end());
	
	sort(y.begin(), y.end());
	
	x.resize(unique(x.begin(), x.end()) - x.begin());
	y.resize(unique(y.begin(), y.end()) - y.begin());
	
	for (int i = 0; i < x.size(); i++)
	{
		mx[x[i]] = i;
	}
	for (int i = 0; i < y.size(); i++)
	{
		my[y[i]] = i;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int xx = mx[a[2*i].fst]; xx < mx[a[2*i+1].fst]; xx++)
		{
			for (int yy = my[a[2*i].snd]; yy < my[a[2*i+1].snd]; yy++)
			{
				b[xx][yy] = 1;
			}
		}
	}
	
	bool good = true;
	
	for (int xx = mx[xmin]; xx < mx[xmax]; xx++)
	{
		for (int yy = my[ymin]; yy < my[ymax]; yy++)
		{
			if (!b[xx][yy])
				good = 0;
		}
	}
	
	if ((xmax-xmin) != (ymax-ymin))
		good = false;
		
	if (good)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}