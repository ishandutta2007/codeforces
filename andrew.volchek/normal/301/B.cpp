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

int g[101][101];
int a[101];
int cc[101][2];
bool was[101];
ll dist[101];
int n, d;

bool fb(int aa)
{
	for (int i = 0; i < n; i++)
		was[i] = false, dist[i] = 0;
		
	was[0] = true;	
	dist[0] = aa;
	
	for (int i = 0; i < n; i++)
	{
		for (int u = 0; u < n-1; u++)
		{
			for (int v = 0; v < n; v++)
			{
				if (v == u)
					continue;
					
				if (was[u])
				{
					int curr = dist[u] + a[u] - g[u][v];
					//cout << u << " " << v << " " << curr << endl;
					if (curr >= dist[v])
					{
						dist[v] = curr;
						was[v] = true;
					}
				}
			}
		}
	}
	
	return was[n-1];
}

int main(int argc, char **argv)
{
	cin >> n >> d;
	
	a[0] = a[n-1] = 0;
	for (int i = 1; i < n-1; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		cin >> cc[i][0] >> cc[i][1];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			g[i][j] = (abs(cc[i][0] - cc[j][0]) + abs(cc[i][1] - cc[j][1])) * d;
		}
	}
	
	int lo = 0;
	int hi = 1000000005;
	while (hi - lo > 1)
	{
		int mid = (lo + hi) / 2;
		
		if (fb(mid))
			hi = mid;
		else
			lo = mid;
	}
	
	cout << hi;
	return 0;
}