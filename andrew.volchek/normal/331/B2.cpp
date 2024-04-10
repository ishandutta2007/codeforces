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


int a[300005];
int pos[300005];
int ans[300005];
int tree[300005];
int n;
int q;

int sum(int r)
{
	int result = 0;
	while (r >= 0)
	{
		result += tree[r];
		r = (r & (r+1)) - 1;
	}
	return result;
}

void inc (int i, int delta)
{
	while (i < n)
	{
		tree[i] += delta;
		i = (i | (i+1));
	}
}

int main(int argc, char **argv)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		pos[x] = i;
	}
	int curr = pos[1];
	
	for (int i = 2; i <= n; i++)
	{
		int next = pos[i];
		if (next < curr)
			inc(i-1, 1);
		curr = next;
	}

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		
		if (type == 1)
		{
			int ans = 1;
			
			ans += sum(y-1) - sum(x-1);
			printf("%d\n", ans);
		}
		else
		{
			int xx = a[x-1];
			int yy = a[y-1];
			
			if (xx < n)
			{
				int nxt = pos[xx+1];
				bool curr = nxt < pos[xx];
				if (curr)
					inc(xx, -1);
				bool became = nxt < (y-1);
				if (became)	
					inc(xx, 1);
			}
			if (xx > 1)
			{
				int prv = pos[xx-1];
				bool curr = pos[xx] < prv;
				if (curr)
					inc(xx-1, -1);
				bool became = (y-1) < prv;
				if (became)	
					inc(xx-1, 1);
			}
			pos[xx] = y-1;
			
			if (yy < n)
			{
				int nxt = pos[yy+1];
				bool curr = nxt < pos[yy];
				if (curr)
					inc(yy, -1);
				bool became = nxt < (x-1);
				if (became)	
					inc(yy, 1);
			}
			if (yy > 1)
			{
				int prv = pos[yy-1];
				bool curr = pos[yy] < prv;
				if (curr)
					inc(yy-1, -1);
				bool became = (x-1) < prv;
				if (became)	
					inc(yy-1, 1);
			}
			pos[yy] = x-1;
			swap(a[x-1], a[y-1]);
			
		}
	}
	/*for (int i = 0; i < n; i++)
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
	}*/
	
	return 0;
}