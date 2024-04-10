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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

struct node
{
	node *l, *r;
	int size;
	int key;
	int pr;
	
	node()
	{
		l = r = NULL;
		size = 1;
		pr = rand();
	}
	
	void update()
	{
		size = 1;
		
		if (l)
			size += l->size;
		
		if (r)
			size += r->size;
	}
};

typedef node* pnode;

int getSize(pnode v)
{
	return v ? v->size : 0;
}

pnode merge(pnode l, pnode r)
{
	if (!l || !r)
		return l ? l : r;
		
	pnode res;
	if (l->pr < r->pr)
	{
		res = l;
		res->r = merge(res->r, r);
	}
	else
	{
		res = r;
		res->l = merge(l, res->l);
	}
	
	res->update();
	return res;
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
		split(l->r, l->r, r, key);
	}
	else
	{
		r = v;
		split(r->l, l, r->l, key);
	}
	
	if (l)
		l->update();
		
	if (r)
		r->update();
}

pnode insert(pnode v, ll key)
{
	pnode left, center, right;
	split(v, left, center, key - 1);
	split(center, center, right, key);
	if (center)
	{
		return merge(left, merge(center, right));
	}
	else
	{
		center = new node();
		center->key = key;
		return merge(merge(left, center), right);
	}
}

pnode mergeSets(pnode v, pnode acc)
{
	if (!v)
		return acc;
	acc = insert(acc, v->key);
	acc = mergeSets(v->l, acc);
	acc = mergeSets(v->r, acc);
	return acc;
}

pair < int, int > queries[100005];
int ans[100005];

struct sa
{
	unordered_map < int, sa* > nxt;
	sa *lnk;
	int len;
	pnode pos;
	sa* lnkP[19];
	bool visited;
	vector < sa* > g;
	vector < int > q;
	
	sa()
	{
		lnk = NULL;
		len = 0;
		pos = NULL;
		visited = false;
		for (int i = 0; i < 19; i++)
			lnkP[i] = NULL;
	}
};

sa *root = new sa();
sa *last = root;
sa *pool[400505];
int poolCnt = 0;
sa *byLen[400505];

void extend(ll x, bool f)
{
	sa *curr = new sa();
	pool[poolCnt++] = curr;
	last->nxt[x] = curr;
	curr->lnk = root;
	curr->len = last->len + 1;
	byLen[curr->len] = curr;
	if (f)
		curr->pos = insert(NULL, curr->len);
	
	sa *v = last->lnk;
	
	while (v != NULL)
	{
		if (!v->nxt.count(x))
		{
			v->nxt[x] = curr;
			v = v->lnk;
		}
		else
		{
			if (v->nxt[x]->len == v->len + 1)
			{
				curr->lnk = v->nxt[x];
			}
			else
			{
				sa *p = v, *q = p->nxt[x];
				sa *clone = new sa();
				pool[poolCnt++] = clone;
				clone->lnk = q->lnk;
				clone->nxt = q->nxt;
				clone->len = p->len + 1;
				q->lnk = clone;
				curr->lnk = clone;
				
				for (; p && p->nxt.count(x) && p->nxt[x] == q; p = p->lnk)
					p->nxt[x] = clone;
			}
			
			break;
		}
	}
	
	last = curr;
}

const int maxn = 100005;

ll a[maxn];

void printSet(node *v)
{
	if (!v)
		return;
	cerr << " " << v->key << endl;
	printSet(v->l);
	printSet(v->r);
}

void compLinks(sa *v)
{
	if (v->visited)
		return;
		
	v->visited = true;
	if (v->lnk)
		compLinks(v->lnk);
		
	v->lnkP[0] = v->lnk;
	
	for (int i = 1; i < 17; i++)
	{
		if (v->lnkP[i - 1])
			v->lnkP[i] = v->lnkP[i - 1]->lnkP[i - 1];
	}
}

pnode dfs(sa *v)
{
	for (auto to : v->g)
	{
		pnode res = dfs(to);
		if (getSize(v->pos) < getSize(res))
			v->pos = mergeSets(v->pos, res);
		else
			v->pos = mergeSets(res, v->pos);
	}
	
	for (int x : v->q)
	{
		int l = queries[x].fst;
		int r = queries[x].snd;
		pnode left, center, right;
		
		split(v->pos, left, center, l - 1);
		split(center, center, right, r + r - l);
		
		ans[x] = getSize(left) + getSize(right);
		
		v->pos = merge(merge(left, center), right);
	}
	
	return v->pos;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	pool[poolCnt++] = root;
		
	for (int i = 1; i < n; i++)
		extend(a[i] - a[i - 1], true);
		
	extend(1e18, false);
	
	for (int i = 1; i < n; i++)
		extend(a[i - 1] - a[i], false);
		
	for (int i = 0; i < poolCnt; i++)
	{
		if (pool[i]->lnk)
			pool[i]->lnk->g.pb(pool[i]);
		compLinks(pool[i]);
	}
	
	
	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		
		queries[i] = mp(l, r);
		
		if (l == r)
		{
			ans[i] = n - 1;
			continue;
		}
		

		sa *v = byLen[n + r];
		
		for (int j = 18; j >= 0; j--)
		{
			if (v->lnkP[j] && v->lnkP[j]->len >= r - l)
				v = v->lnkP[j];
		}
		
		v->q.pb(i);
		
		
		/*pnode left, center, right;
		
		splitNotP(v->pos, left, center, l - 1);
		splitNotP(center, center, right, r + r - l);
		
		printf("%d\n", getSize(left) + getSize(right));
		
		v->pos = mergeNotP(mergeNotP(left, center), right);*/
	}
	
	
	for (int i = 0; i < poolCnt; i++)
		if (!pool[i]->lnk)
			dfs(pool[i]);
			
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}