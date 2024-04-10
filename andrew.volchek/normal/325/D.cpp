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


int v[3005*6005];
char used[3005][6005];

int get(int i)
{
	if (v[i] == i)
		return i;
	else
		return v[i] = get(v[i]);
}

void unite(int a, int b)
{
	int i = get(a);
	int j = get(b);
	
	if (i != j)
	{
		if (rand() & 1)
			swap(i, j);
		v[i] = j;
	}
}

int r, c, n, cnt;

int cc(int x, int y)
{
	return x * c * 2 + y;
}

int main(int argc, char **argv)
{
	scanf("%d %d %d", &r, &c, &n);
	r += 2;
	cnt = r * c * 2;
	for (int i = 0; i < cnt; i++)
		v[i] = i;
		
	if (c == 1)
	{
		cout << 0;
		return 0;
	}

	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		//x--;
		y--;
		
		bool middle = false;
		
		vector < int > mm[2];
		
		for (int h = 0; h < 2; h++)
		{			
			for (int dx = -1; dx <= 1; dx++)
			{
				for (int dy = -1; dy <= 1; dy++)
				{				
					int xx = (x + dx) % r;
					int yy = (y + dy + c*h) % (2*c);
					if (yy < 0)
						yy += 2*c;
					
					if (0 <= xx && xx < r && 0 <= yy && yy < c*2)
					{
						if (used[xx][yy])
						{
							mm[h].pb(get(cc(xx, yy)));;
						}
					}
				}
			}
		}
		
		for (int i = 0; i < mm[0].size(); i++)
			for (int j = 0; j < mm[1].size(); j++)
			{
				if (mm[0][i] == mm[1][j])
					middle = true;
			}
		
		/*for (map < int, int > :: iterator it = mm.begin(); it != mm.end(); it++)
		{
			if (it->second == 3)
				middle = true;
		}*/
		
		
		if (!middle)
		{
			ans++;
			
			for (int h = 0; h < 2; h++)
			{
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 1; dy++)
					{				
						int xx = (x + dx) % r;
						int yy = (y + dy + c*h) % (2*c);
						if (yy < 0)
							yy += 2*c;
						
						if (0 <= xx && xx < r && 0 <= yy && yy < c*2)
						{
							if (used [xx][yy])
							{
								unite(cc(xx, yy), cc(x, y + c*h));
							}
						}
					}
				}
			}
			
			used[x][y] = true;
			used[x][y+c] = true;
		}
	}
	
	
	cout << ans;
	
	return 0;
}