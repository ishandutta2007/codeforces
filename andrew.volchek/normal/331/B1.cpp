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


int a[105];
int next[105];
int rev[105];
int n;
int q;

int main(int argc, char **argv)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	next[n] = -1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j]-1 == i)
				next[i] = j;
		}
	}
	for (int i = 0; i < n; i++)
		rev[a[i]] = i;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		
		if (type == 1)
		{
			int ans = 1;
			
			int curr = rev[x];
			while (a[curr] != y)
			{
				if (next[a[curr]] < curr)
				{
					ans++;
				}
				curr = next[a[curr]];
			}
			printf("%d\n", ans);
		}
		else
		{
			int xx = a[x-1];
			int yy = a[y-1];
			if (xx > 1)
			{
				next[xx-1] = y-1;
			}
			if (yy > 1)
			{
				next[yy-1] = x-1;
			}
			
			swap(rev[a[x-1]], rev[a[y-1]]);
			swap(a[x-1], a[y-1]);
			
		}
	}
	
	return 0;
}