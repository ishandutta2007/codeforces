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

const int maxn = 2020000;

int p[maxn][22];
int h[maxn];

int vcnt = 4;


int lca(int v1, int v2)
{
	if (h[v1] < h[v2])
		swap(v1, v2);
		
	int diff = h[v1] - h[v2];
		
	for (int i = 0; i < 22; i++)
	{
		if (diff & (1 << i))
			v1 = p[v1][i];
	}
	
	if (v1 == v2)
		return v1;
		
	int ans;
	
	for (int i = 21; i >= 0; i--)
	{
		if (p[v1][i] == p[v2][i])
		{
			ans = p[v1][i];
		}
		else
		{
			v1 = p[v1][i];
			v2 = p[v2][i];
		}
	}
	
	return ans;
}

int ans1 = 2, ans2 = 3;
int ans = 2;
	
void update(int v)
{
	int l1 = lca(ans1, v);
		int dist1 = abs(h[l1] - h[ans1]) + abs(h[l1] - h[v]);
		
		
		int l2 = lca(ans2, v);
		int dist2 = abs(h[l2] - h[ans2]) + abs(h[l2] - h[v]);
		
		int gr = 1;
		if (dist2 > dist1)
		{
			dist1 = dist2;
			gr = 2;
		}
		
		/*if (dist1 == 4)
		{
			cerr << ans << " " << ans1 << " " << ans2 << endl;
			cerr << l1 << " " << l2 << endl;
			cerr << v << endl;
		}*/
		
		if (dist1 > ans)
		{
			ans = dist1;
			if (gr == 1)
				ans2 = v;
			else
				ans1 = v;
		}
}
/*
 * 3
4
4
5
6*/

int main()
{
	//freopen("a.in", "r", stdin);
	
	int q;
	scanf("%d", &q);
	
	
	h[1] = 0;
	h[2] = h[3] = h[4] = 1;
	
	for (int i = 0; i < 22; i++)
		p[1][i] = 1;
		
	for (int i = 2; i <= 4; i++)
	{
		for (int j = 0; j < 22; j++)
			p[i][j] = 1;
	}
	
	
	
	for (int i = 0; i < q; i++)
	{
		int v;
		scanf("%d", &v);
		
		h[vcnt + 1] = h[v] + 1;
		h[vcnt + 2] = h[v] + 1;
		
		p[vcnt + 1][0] = v;
		p[vcnt + 2][0] = v;
		
		for (int j = 1; j < 22; j++)
		{
			p[vcnt + 1][j] = p[p[vcnt + 1][j-1]][j-1];
			p[vcnt + 2][j] = p[p[vcnt + 2][j-1]][j-1];
		}
		
		
			
		update(vcnt + 1);
		update(vcnt + 2);
		vcnt += 2;
		
		printf("%d\n", ans);
		
	}
	
	//cerr << lca(5, 6) << endl;
	return 0;
}