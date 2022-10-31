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
#include <cstdlib>
#include <algorithm>

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


int f(int n, int k)
{
	int res = k;
	if (res == 0)
		return 0;
	for (int i = 0; i < n; i++)
	{
		int up =  31 - __builtin_clz(res);
		/*int up2;
		for (int j = 0; j < 20; j++)
			if (res & (1 << j))
				up2 = j;
		assert(up2 == up);*/
				
		res = res + up + 1;
		//cerr << res << endl;
	}
	return res;
}

bool inter(int l1, int r1, int l2, int r2)
{
	return !((l1 > r2) || (l2 > r1));
}

struct query
{
	int type;
	int t, l, r, x;
};



vector < int > ans[7005];
vector < query > qAdd, qAsk;
vector < int > tAdd, tAsk;

void gen()
{
	freopen("a.in", "w", stdout);
	cout << 7000 << " " << 7000 << endl;;
	for (int i = 0; i < 3500; i++)
		cout << "1 2 1 1" << endl;
	for (int j = 0; j < 3500; j++)
		cout << "2 1 1" << endl;
	exit(0);
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		query q;
		
		scanf("%d", &q.type);
		
		if (q.type == 1)
		{
			scanf("%d %d %d %d", &q.t, &q.l, &q.r, &q.x);
			int l, r;
			l = f(n - q.t, q.l-1) + 1;
			r = f(n - q.t, q.r);
			//cerr << l << " " << r << endl;
			q.l = l;
			q.r = r;
			qAdd.pb(q);
			tAdd.pb(i);
		}
		else
		{
			scanf("%d %d", &q.t, &q.l);
			int l, r;
			l = f(n - q.t, q.l-1) + 1;
			r = f(n - q.t, q.l);
			q.l = l;
			q.r = r;
			//cerr << l << " " << r << endl;
			qAsk.pb(q);
			tAsk.pb(i);
		}
	}
	//cerr << (ld)clock() / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < qAdd.size(); i++)
	{
		int l = qAdd[i].l;
		int r = qAdd[i].r;
		int t = qAdd[i].t;
		int x = qAdd[i].x;
		for (int j = 0; j < qAsk.size(); j++)
		{
			if (tAdd[i] <= tAsk[j] && t >= qAsk[j].t && inter(l, r, qAsk[j].l, qAsk[j].r))
			{
				ans[j].pb(x);
			}
		}
	}
	
	for (int i = 0; i < qAsk.size(); i++)
	{
		sort(ans[i].begin(), ans[i].end());
		int len = unique(ans[i].begin(), ans[i].end()) - ans[i].begin();
		printf("%d\n", len);
	}
	//cerr << (ld)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}