#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <vector>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define y1 asdkjghjasd
#define fst first
#define snd second
#define y0 sakjglajaa
#define ll long long
#define ull unsigned long long
#define ld long double

const int maxn = 200005;

const ll mod[3] = { 1000000007, 1000000009, 1000000007 };
const ll base[3] = { 200003, 200231, 316031 }; 
const int hcnt = 3;

ll pows[hcnt][maxn];

struct hh
{
	ll v[hcnt];
	
	hh()
	{
		for (int i = 0; i < hcnt; i++)
			v[i] = 0;
	}
	
	hh(int x)
	{
		for (int i = 0; i < hcnt; i++)
			v[i] = x % mod[i];
	}
	
	hh operator << (const int x)
	{
		hh res;
		for (int i = 0; i < hcnt; i++)
			res.v[i] = (v[i] * pows[i][x]) % mod[i];
		return res;
	}
	
	hh operator - (const hh &r)
	{
		hh res;
		for (int i = 0; i < hcnt; i++)
			res.v[i] = (v[i] - r.v[i] + mod[i]) % mod[i];
		return res;
	}
	
	hh operator + (const hh &r)
	{
		hh res;
		for (int i = 0; i < hcnt; i++)
			res.v[i] = (v[i] + r.v[i]) % mod[i];
		return res;
	}
	
	bool operator == (const hh &r)
	{
		for (int i = 0; i < hcnt; i++)
			if (v[i] != r.v[i])
				return false;
		return true;
	}
};

char a[maxn];
char b[maxn];

int bnxt[maxn];
int anxt[maxn], aprv[maxn];

int par[30];

int main()
{
	//freopen("a.in", "r", stdin);
	
	for (int i = 0; i < hcnt; i++)
	{
		pows[i][0] = 1;
		for (int j = 1; j < maxn; j++)
			pows[i][j] = (pows[i][j - 1] * base[i]) % mod[i];
	}
	
	int n, m;
	
	scanf("%d %d\n", &n, &m);
	//n = 200000;
	//m = 200;
	
	scanf("%s", a);
	scanf("%s", b);
	
	/*for (int i = 0; i < n; i++)
		a[i] = i % 26 + 'a';
	for (int i = 0; i < m; i++)
		b[i] = i % 26 + 'a';
	
	*/

	map < char, int > was;
	
	for (int i = m - 1; i >= 0; i--)
	{
		if (was.count(b[i]) == 0)
		{
			bnxt[i] = 0;
		}
		else
		{
			bnxt[i] = was[b[i]] - i;
		}
		
		was[b[i]] = i;
	}
	
	vector < int > ans;
	
	was.clear();
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (was.count(a[i]) == 0)
			anxt[i] = 0;
		else
			anxt[i] = was[a[i]] - i;
		was[a[i]] = i;
	}
	
	was.clear();
	
	
	for (int i = 0; i < n; i++)
	{
		if (was.count(a[i]) == 0)
			aprv[i] = 0;
		else
			aprv[i] = i - was[a[i]];
		was[a[i]] = i;
	}
	
	hh x;
	
	hh y;
	
	for (int i = 0; i < m; i++)
	{
		hh c(bnxt[i]);
		c = c << (m - 1 - i);
		y = y + c;
	}
	
	
	vector < int > nice;
	was.clear();
	for (int i = 0; i < m; i++)
	{
		if (was.count(b[i]))
			continue;
		nice.pb(i);
		was[b[i]] = i;
	}
	
	
	for (int i = 0; i < m; i++)
	{
		int v = anxt[i];
		if (i + v >= m)
			v = 0;
	
		hh c(v);
		c = c << (m - 1 - i);
		
		x = x + c;
	}
	
	if (x == y)
		ans.pb(0);
		
	for (int i = m; i < n; i++)
	{
		int v = anxt[i - m];
		if (i - m + v >= i)
			v = 0;

		hh c(v);
		c = c << (m - 1);
		x = x - c;
		
		x = x << 1;
		
		if (aprv[i] != 0)
		{
			int prvP = i - aprv[i];
			if (prvP >= i - m + 1)
			{
				hh c(anxt[prvP]);
				c = c << (i - prvP);
				x = x + c;
			}
		}
		
		if (x == y)
			ans.pb(i - m + 1);
	}
	
	
	vector < int > ans2;
	
	for (int x : ans)
	{
		bool good = true;
		
		for (int i = 0; i < 26; i++)
			par[i] = -1;
		
		for (int y : nice)
		{
			int z = x + y;
			
			if (par[a[z] - 'a'] == -1 && par[b[y] - 'a'] == -1)
			{
				par[a[z] - 'a'] = b[y] - 'a';
				par[b[y] - 'a'] = a[z] - 'a';
			}
			else if (par[a[z] - 'a'] != -1 && par[b[y] - 'a'] != -1)
			{
				good &= par[a[z] - 'a'] == b[y] - 'a';
				good &= par[b[y] - 'a'] == a[z] - 'a';
			}
			else
				good = false;
		}
		
		if (good)
			ans2.pb(x);
	}
	
	printf("%d\n", ans2.size());
	
	for (int i = 0; i < ans2.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans2[i] + 1);
	}
	
	
	//cin >> t;
	return 0;
}