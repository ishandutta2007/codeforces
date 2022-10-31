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
#define y1 _y1
#define left _left

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

struct node
{
	node *l, *r;
	int key;
	int pr;
	int size;
	
	node()
	{
		l = r = NULL;
		pr = rand();
		size = 1;
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

int getSize(pnode v)
{
	return v ? v->size : 0;
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

struct nodeG
{
	nodeG *l, *r;
	pair < int, int > key;
	int pr;
	int size;
	int id;
	nodeG()
	{
		l = r = NULL;
		pr = rand();
		size = 1;
		id = 0;
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
typedef nodeG* pnodeG;

pnodeG mergeG(pnodeG l, pnodeG r)
{
	if (!l || !r)
		return l ? l : r;
	if (l->pr > r->pr)
	{
		l->r = mergeG(l->r, r);
		l->update();
		return l;
	}
	else
	{
		r->l = mergeG(l, r->l);
		r->update();
		return r;
	}
}

int getSizeG(pnodeG v)
{
	return v ? v->size : 0;
}

void splitG(pnodeG v, pnodeG &l, pnodeG &r, ll key)
{
	if (!v)
	{
		l = r = NULL;
		return;
	}
	
	if (v->key.snd <= key)
	{
		l = v;
		splitG(v->r, l->r, r, key);
	}
	else
	{
		r = v;
		splitG(v->l, l, r->l, key);
	}
	if (l)
		l->update();
	if (r)
		r->update();
}


const int maxn = 400005;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];

int dsu[maxn];

int find(int v)
{
	if (dsu[v] == v)
		return v;
	return dsu[v] = find(dsu[v]);
}

bool unite(int i, int j)
{
	int a = find(i);
	int b = find(j);
	
	if (a != b)
	{
		if (rand() & 1)
			swap(a, b);
		dsu[a] = b;
		
		return true;
	}
	
	return false;
}

vector < nodeG* > dfsRes;
void dfs(nodeG *v)
{
	if (!v)
		return;
	dfs(v->l);
	dfsRes.pb(v);
	dfs(v->r);
}

ll ans[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	vector < pair < int, pair < int, int > > > ev;
	for (int i = 0; i < maxn; i++) dsu[i] = i;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", x1 + i, y1 + i, x2 + i, y2 + i);
		
		if (x1[i] == x2[i])
		{
			ev.pb(mp(x1[i], mp(0, i)));
		}
		else
		{
			ev.pb(mp(x1[i], mp(-1, i)));
			ev.pb(mp(x2[i], mp(1, i)));
		}
	}
	sort(ev.begin(), ev.end());
	node *root = NULL;
	nodeG *rootG = NULL;
	for (int i = 0; i < ev.size(); i++)
	{
		int j = i;
		while (j < ev.size() && ev[i].fst == ev[j].fst) j++;
		for (int h = i; h < j; h++)
		{
			int ind = ev[h].snd.snd;
			
			if (ev[h].snd.fst == -1)
			{
				//cerr << "add " << ind << endl;
				ans[ind] += x2[ind] - x1[ind];
				int y = y1[ind];
				nodeG *v = rootG;
				while (v)
				{
					if (y < v->key.fst)
					{
						v = v->l;
					}
					else if (v->key.snd < y)
					{
						v = v->r;
					}
					else
						break;
				}
				
				if (v != NULL)
				{
					pair < int, int > gr = v->key;
					int grId = v->id;
					pnodeG left, center, right;
					splitG(rootG, left, right, gr.snd);
					splitG(left, left, center, gr.snd - 1);
					
					
					node *v2 = root;
					int lb = -1e9 - 1;
					while (v2)
					{
						if (v2->key < y)
						{
							lb = max(lb, v2->key);
							v2 = v2->r;
						}
						else
						{
							v2 = v2->l;
						}
					}
					
					node *v3 = root;
					int ub = 1e9 + 1;
					while (v3)
					{
						if (v3->key <= y)
						{
							v3 = v3->r;
						}
						else
						{
							ub = min(ub, v3->key);
							v3 = v3->l;
						}
					}
					
					
					
					pnodeG n1, n2, n3;
					n1 = new nodeG();
					n1->key = mp(gr.fst, lb);
					n1->id = grId;
					n2 = new nodeG();
					n2->key = mp(y, y);
					n2->id = ind;
					n3 = new nodeG();
					n3->key = mp(ub, gr.snd);
					n3->id = grId;
					rootG = mergeG(left, mergeG(n1, mergeG(n2, mergeG(n3, right))));
				}
				else
				{
					pnodeG n1;
					pnodeG left, right;
					splitG(rootG, left, right, y - 1);
					n1 = new nodeG();
					n1->key = mp(y, y);
					n1->id = ind;
					rootG = mergeG(left, mergeG(n1, right));
				}
				
				
				pnode l, r;
				split(root, l, r, y - 1);
				pnode n1 = new node();
				n1->key = y;
				root = merge(l, merge(n1, r));
			}
			else if (ev[h].snd.fst == 0)
			{
				//cout << "q " << ind << endl;
				ans[ind] += y2[ind] - y1[ind];
				pnode left, center, right;
				split(root, left, right, y1[ind] - 1);
				split(right, center, right, y2[ind]);
				ans[ind] -= max(0, getSize(center) - 1);
				//cerr << getSize(center) << endl;
				int inter = getSize(center);
				root = merge(left, merge(center, right));
				
				if (!inter)
					continue;
				
				
				int lb = -1e9 - 1;
				pnodeG v = rootG;
				while (v)
				{
					if (v->key.snd < y1[ind])
					{
						lb = max(lb, v->key.snd);
						v = v->r;
					}
					else
					{
						v = v->l;
					}
				}
				v = rootG;
				int up = 1e9 + 1;
				while (v)
				{
					if (y2[ind] < v->key.fst)
					{
						up = min(up, v->key.snd);
						v = v->l;
					}
					else
					{
						v = v->r;
					}
				}
				
				pnodeG lg, cg, rg;
				splitG(rootG, lg, rg, lb);
				splitG(rg, cg, rg, up - 1);				
				
				if (cg)
				{
					dfsRes.clear();
					dfs(cg);
					
					unite(dfsRes[0]->id, ind);
					for (int g = 0; g + 1 < dfsRes.size(); g++)
					{
						if (unite(dfsRes[g]->id, dfsRes[g + 1]->id))
						{
							ans[ind]++;
							//cerr << ind << endl;
						}
					}
					//unite(dfsRes.back()->id, ind);
					//ans[ind] += uniteDfs(cg, ind);
					
					pnodeG lv = cg, rv = cg;
					while (lv && lv->l)
						lv = lv->l;
					
					while (rv && rv->r)
						rv = rv->r;
						
					pnodeG ncg = new nodeG();
					ncg->key = mp(lv->key.fst, rv->key.snd);
					ncg->id = ind;
					rootG = mergeG(lg, mergeG(ncg, rg));	
				}
				else
					rootG = mergeG(lg, mergeG(cg, rg));
			}
			else
			{
				//cout << "del " << ind << endl;
				int y = y1[ind];
				nodeG *v = rootG;
				while (v)
				{
					if (y < v->key.fst)
					{
						v = v->l;
					}
					else if (v->key.snd < y)
					{
						v = v->r;
					}
					else
						break;
				}
				
				//assert(v);
				
				
				pnodeG left, center, right;
				splitG(rootG, left, right, v->key.snd - 1);
				splitG(right, center, right, v->key.snd);
				
				
				pair < int, int > res = v->key;
				
				if (res.snd == y)
				{
					int lb = -1e9 - 1;
					node *v = root;
					while (v)
					{
						if (v->key < y)
						{
							lb = max(lb, v->key);
							v = v->r;
						}
						else
						{
							v = v->l;
						}
					}
					
					res.snd = lb;
					center->key = res;
					
					if (res.fst <= res.snd)
						rootG = mergeG(left, mergeG(center, right));
					else
						rootG = mergeG(left, right);
				}
				else if (res.fst == y)
				{
					int ub = 1e9 + 1;
					node *v = root;
					while (v)
					{
						if (v->key <= y)
							v = v->r;
						else
						{
							ub = min(ub, v->key);
							v = v->l;
						}
					}
					
					
					res.fst = ub;
					center->key = res;
					if (res.fst <= res.snd)
						rootG = mergeG(left, mergeG(center, right));
					else
						rootG = mergeG(left, right);
				}
				else
					rootG = mergeG(left, mergeG(center, right));
					
					
				pnode l, c, r;
				split(root, l, r, y);
				split(l, l, c, y - 1);
				root = merge(l, r);
			}
		}
		
		i = j - 1;
	}
	
	ll gAns = -1e18;
	
	for (int i = 0; i < maxn; i++)
	{
		if (find(i) != i)
			ans[find(i)] += ans[i];
	}
	
	for (int i = 0; i < maxn; i++)
		if (find(i) == i)
			gAns = max(gAns, ans[i]);
	
	cout << gAns;
	
	return 0;
}