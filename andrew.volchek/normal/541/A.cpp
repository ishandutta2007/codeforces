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
#include <unordered_map>
#include <ctime>
#include <functional>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

struct node
{
	node *l, *r;
	ll key;
	int pr;
	pair < ll, int > val;
	pair < ll, int > ans;
	
	node()
	{
		l = r = NULL;
		pr = rand();
	}
	
	void update()
	{
		ans = val;
		if (l)
			ans = max(ans, l->ans);
		if (r)
			ans = max(ans, r->ans);
	}
};

typedef node* pnode;

pnode merge(pnode l, pnode r)
{
	if (!l || !r)
		return l ? l : r;
	if (l->pr > r->pr)
	{
		l->r = merge(l->r, r);
		l->update();
		return l;
	}
	else
	{
		r->l = merge(l, r->l);
		r->update();
		return r;
	}
}

void split(pnode v, pnode &l, pnode &r, ll key)
{
	if (!v)
	{
		l = r = NULL;
		return;
	}
	
	if (v->key <= key)
	{
		l = v;
		split(v->r, l->r, r, key);
	}
	else
	{
		r = v;
		split(v->l, l, r->l, key);
	}
	
	if (l)
		l->update();
	if (r)
		r->update();
}

struct ev
{
	ll x;
	ll l;
	int type; // 0 - start r, 1 - end r, 2 - start ch, 3 - end ch
	ll cost;
	int idx;
	bool operator < (const ev &o) const
	{
		return (x < o.x) || (x == o.x && type < o.type);
	}
};

pair < ll, pair < int, int > > ans(0, mp(-1, -1));

void solve(vector < ev > a)
{
	sort(a.begin(), a.end());

	multiset < pair < ll, int >  > opened;
	pnode v = NULL;
	
	for (auto e : a)
	{
		
		if (e.type == 0)
		{
			opened.insert(mp(e.x, e.idx));
		}
		else if (e.type == 1)
		{
			opened.erase(mp(e.l, e.idx));

			pnode l, r;
			split(v, l, r, e.l - 1);
			pnode c = new node();
			c->key = e.l;
			c->val = c->ans = mp(e.x - e.l, e.idx);
			v = merge(l, merge(c, r));
		}
		else if (e.type == 2)
		{
		}
		else
		{
			if (opened.size())
			{
				auto x = *opened.begin();
				x.fst = max(x.fst, e.l);
				ll c = (e.x - x.fst) * e.cost;
				
				ans = max(ans, mp(c, mp(x.snd, e.idx)));
				
				
			}
			
			
			pnode l, r;
			split(v, l, r, e.l - 1);
			if (r)
			{
				ll c = r->ans.fst * e.cost;
				ans = max(ans, mp(c, mp(r->ans.snd, e.idx)));
			}
			
			v = merge(l, r);
		}
	}
}


int main()
{
	srand(time(NULL));
	//freopen("a.in", "r", stdin);
	//gen();
	
	
	int n, m;
	scanf("%d %d", &n, &m);
	//n = 200000, m = 200000;
	
	vector < pair < int, int > > r;
	vector < pair < pair < int, int >, int > > ch;
	
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		/*a = rand() % 10000000, b = rand() % 10000000;
		if (a > b)
			swap(a, b);*/
		r.pb(mp(a, b));
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		/*a = rand() % 10000000, b = rand() % 10000000;
		if (a > b)
			swap(a, b);*/
		ch.pb(mp(mp(a, b), c));
	}
	
	
	const int inf = 1e9 + 5;
	
	for (int iter = 0; iter < 2; iter++)
	{
		vector < ev > e;
		
		for (int i = 0; i < n; i++)
		{
			ev u;
			u.x = r[i].fst;
			u.type = 0;
			u.idx = i;
			e.pb(u);
			
			u.x = r[i].snd;
			u.type = 1;
			u.idx = i;
			u.l = r[i].fst;
			e.pb(u);
		}
		
		//cerr << 1 << endl;
	
		
		for (int i = 0; i < m; i++)
		{
			ev u;
			u.x = ch[i].fst.fst;
			u.type = 2;
			u.idx = i;
			u.cost = ch[i].snd;
			e.pb(u);
			
			u.x = ch[i].fst.snd;
			u.type = 3;
			u.idx = i;
			u.l = ch[i].fst.fst;
			u.cost = ch[i].snd;
			e.pb(u);
		}
		
		solve(e);
		
		for (auto &x : r)
			x = mp(inf - x.snd, inf - x.fst);
			
		for (auto &x : ch)
			x = mp(mp(inf - x.fst.snd, inf - x.fst.fst), x.snd);
	}
	
	if (ans.fst == 0)
		cout << 0 << endl;
	else
	{
		cout << ans.fst << endl;
		cout << ans.snd.fst + 1 << " " << ans.snd.snd + 1 << endl;
	}
	
	
	
	return 0;
}