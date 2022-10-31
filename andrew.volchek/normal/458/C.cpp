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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;

pair < int, int > a[maxn];
vector < ll > c[maxn];

int tree[maxn * 4];
ll sum[maxn * 4];

void inc(int v, int l, int r, int i)
{
	if (l == r)
	{
		tree[v]++;
		sum[v] += l;
		return;
	}
	
	int c = (l + r) >> 1;
	
	if (i <= c)
		inc(2 * v, l, c, i);
	else
		inc(2 * v + 1, c + 1, r, i);
		
	tree[v] = tree[2 * v] + tree[2 * v + 1];
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

ll get(int v, int l, int r, int need)
{
	if (l == r)
	{
		return (ll)l * need;
	}
	
	ll res = 0;
	int c = (l + r) >> 1;
	
	if (tree[2 * v] >= need)
	{
		res = get(2 * v, l, c, need);
	}
	else
	{
		res = sum[2 * v] + get(2 * v + 1, c + 1, r, need - tree[2 * v]);
	}
	
	return res;
}

int main(int argc, char *argv[])
{
	//cerr << int((ll)1e10) << endl;
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].fst, &a[i].snd);
		
		if (a[i].fst == 0)
			cnt++;
		else
			c[a[i].fst].pb(a[i].snd);
	}
	
	ll ans = 1e18;
	ll curr = 0;
	int currCnt = 0;
	
	vector < vector < ll >* > s;
	
	const ll inf = 1e10;
	
	for (int i = 0; i < maxn; i++)
	{
		if (c[i].size() > 0)
		{
			sort(c[i].begin(), c[i].end());
			c[i].pb(inf);
			
			vector < ll > *v = new vector < ll >();
			int j = 0;
			for (j = 0; j < min(int(c[i].size()), int(c[i].size() - 1) - cnt + 1); j++)
			{
				v->pb(c[i][j]);
				curr += c[i][j];
				if (c[i][j] != inf)
					currCnt++;
			}
			
			if (v->size() > 0)
				s.pb(v);
			
			for (; j < c[i].size(); j++)
			{
				if (c[i][j] != inf)
					inc(1, 0, maxn - 1, c[i][j]);
			}
		}
	}
	
	cerr << curr << endl;
	ans = min(curr, ans);
	
	int g = cnt;
	while (true)
	{
		
		if (s.empty())
			break;
		g++;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i]->empty())
				exit(1);
			//cerr << "s " << s[i]->size() << endl;
			curr -= s[i]->back();
			if (s[i]->back() != inf)
				inc(1, 0, maxn - 1, s[i]->back());
			
			if (s[i]->back() != inf)
				currCnt--;
				
			s[i]->pop_back();
			
			if (s[i]->size() > 0 && s[i]->back() == inf)
				s[i]->pop_back();
		}
		
		
		vector < vector < ll >* > s2;
		for (int i = 0; i < s.size(); i++)
			if (s[i]->size() > 0)
				s2.pb(s[i]);
				
		s = s2;
				
		
		//cerr << g << " " <<curr << " " << g - cnt - currCnt<< endl;
		if (tree[1] < max(0, g - cnt - currCnt))
			continue;
				
		ans = min(ans, curr + get(1, 0, maxn - 1, max(0, g - cnt - currCnt)));
	}
	
	cout << ans << endl;
	
	return 0;
}