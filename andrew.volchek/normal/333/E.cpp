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
#include <bitset>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

ull dist[9000005];
int cnt = 0;
bitset < 3005 > v[3005];
int x[3005];
int y[3005];


//

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d %d", x+i, y+i);
		
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
		{
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			dist[cnt] = dx*dx + dy*dy;
			dist[cnt] = (dist[cnt] << 12) | i;
			dist[cnt] = (dist[cnt] << 12) | j;
			cnt++;
		}
	
	sort(dist, dist + cnt);
	
	for (int i = cnt-1; i >= 0; i--)
	{
		int a = dist[i] & ((1 << 12) - 1);
		dist[i] >>= 12;
		int b = dist[i] & ((1 << 12) - 1);
		dist[i] >>= 12;
		
		if ((v[a] & v[b]).count())
		{
			cout.precision(8);
			cout << fixed << sqrt((ld)dist[i]) / 2.0 << endl;
			return 0;
		}
		
		v[a][b] = 1;
		v[b][a] = 1;
	}
		
	return 0;
}