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

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

struct node;
int getSize(node *v);

struct node
{
	node *l, *r;
	int size, pr;
	int val, idx;
	
	node() 
	{
		l = r = NULL;
		size = 1;
		pr = rand();
	}
	
	void update()
	{
		size = 1 + getSize(l) + getSize(r);
	}
};

typedef node* pnode;

int getSize(node *v)
{
	return (v == NULL) ? 0 : v->size;
}

pnode merge(pnode l, pnode r)
{
	if (!l || !r)
	{
		return !l ? r : l;
	}
	
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

void split(pnode v, pnode &l, pnode &r, int key)
{
	if (!v)
	{
		l = r = NULL;
		return;
	}
	
	if (1 + getSize(v->l) <= key)
	{
		l = v;
		split(v->r, l->r, r, key - (1 + getSize(v->l)));
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

const int maxn = 1000005;
int used[maxn];
int ans[maxn];

void dfs(pnode v)
{
	if (v == NULL)
		return;
		
	ans[v->idx] = v->val;
	
	if (v->val != -1)
	{
		if (used[v->val])
		{
			cout << -1;
			exit(0);
		}
		used[v->val] = 1;
	}
		
	dfs(v->l);
	dfs(v->r);
}


int main()
{
	//freopen("a.in", "r", stdin);
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	pnode root = NULL;
	
	for (int i = 0; i < n; i++)
	{
		pnode v = new node();
		v->val = -1;
		v->idx = i;
		root = merge(root, v);
	}
	
	
	
	for (int i = 0; i < m; i++)
	{
		int xi, yi;
		scanf("%d %d", &xi, &yi);
		
		pnode left, center, right;
		split(root, left, center, yi - 1);
		split(center, center, right, 1);
		
		if (center->val != -1 && center->val != xi)
		{
			cout << -1 << endl;
			return 0;
		}
		
		center->val = xi;
		
		root = merge(merge(center, left), right);
	}
	
	dfs(root);
	
	int p = 1;
	
	for (int i = 0; i < n; i++)
	{
		while (p < maxn && used[p]) p++;
		
		if (ans[i] == -1)
		{
			//cerr << i << endl;
			ans[i] = p;
			p++;
		}
	}
	
	
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}

	return 0;
}