#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

typedef struct item * pitem;
struct item {
	int prior, value, cnt;
	pitem l, r;
	
	void print()
	{
		if (l) l->print();
		printf("%d ", value);
		if (r) r->print();
	}
};

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t)
		return void( l = r = 0 );
		
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
	upd_cnt (t);
}

void solve()
{
	int n, nOps;
	scanf("%d %d", &n, &nOps);
	
	item* tree = 0;
	
	for (int i = 0; i < n; i++)
		merge(tree, tree, new item { rand(), i, 0, 0, 0 });
		
	vector<int> marked(n, -1);
	vector<bool> markUsed(n, false);
		
	bool failure = false;
		
	for (int i = 0; i < nOps; i++)
	{
		int mark, pos;
		scanf("%d %d", &mark, &pos);
		pos--;
		mark--;
		
		#if 0
		tree->print();
		printf("\n");
		#endif
		
		pitem left, middle, right;
		split(tree, left, middle, pos);
		split(middle, middle, right, 1);
		
		assert(middle);
		assert(!middle->l && !middle->r);
		
		int idx = middle->value;
		assert(idx >= 0 && idx < n);
		markUsed[mark] = true;
		if (marked[idx] != mark && marked[idx] != -1)
		{
			failure = true;
			#ifndef LOCAL
			break;
			#endif
		}
		
		//printf("on %d is now %d\n", idx + 1, mark + 1);
		marked[idx] = mark;
		
		merge(tree, middle, left);
		merge(tree, tree, right);
	}
	
	if (failure)
	{
		printf("-1\n");
		return;
	}
	
	int l = 0;
	
	for (int i = 0; i < n; i++)
		if (marked[i] == -1)
		{
			while (markUsed[l]) l++;
			markUsed[l] = true;
			
			marked[i] = l;
		}
		
	#if 1
	vector<int> c = marked;
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	
	#if 0
	for (int i = 0; i < c.size(); i++)
		printf("%d ", c[i]);
	printf("\n");
	#endif
	
	if ((int)c.size() != n)
	{
		printf("-1\n");
		return;
	}
	#endif
	
	for (int i = 0; i < n; i++)
		printf("%d ", marked[i] + 1);
	printf("\n");
}

int main()
{
	#ifdef LOCAL
	freopen("d.in", "r", stdin);
	int nTests;
	scanf("%d", &nTests);
	for (int i = 0; i < nTests; i++)
	{
		solve();
		printf("\n");
	}
	#else
	solve();
	#endif
	
	return 0;
}