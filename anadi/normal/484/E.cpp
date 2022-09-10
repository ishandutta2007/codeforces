#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 1 << 17;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

struct tree{
	int add = 0;
	int mx = 0;	
	tree *left = nullptr, *right = nullptr;
};

int n;
PII h[N];
bool is[N];
int rep[N];
tree *root[N];

tree* build(int h){
	if(h == 0)
		return new tree();
	
	tree *ret = new tree();
	ret -> left = build(h - 1);
	ret -> right = build(h - 1);
	return ret;
}

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	rep[Find(b)] = Find(a);
}

int ask(tree *cur, int from, int to, int p = 1, int k = T){
	if(from <= p && k <= to)
		return cur -> mx;
	
	int ret = 0;
	int m = (p + k) >> 1;

	if(from <= m)
		ret = max(ret, ask(cur -> left, from, to, p, m));
	if(m < to)
		ret = max(ret, ask(cur -> right, from, to, m + 1, k));
	return ret + (cur -> add);
}

tree* add(tree *cur, int from, int to, int val, int p = 1, int k = T){
	tree *ret = new tree();
	ret -> left = cur -> left;
	ret -> right = cur -> right;
	ret -> add = cur -> add;
	ret -> mx = cur -> mx;

	if(from <= p && k <= to){
		ret -> add += val;
		ret -> mx += val;
		return ret;
	}
	
	int m = (p + k) >> 1;
	if(from <= m)
		ret -> left = add(cur -> left, from, to, val, p, m);
	if(m < to)
		ret -> right = add(cur -> right, from, to, val, m + 1, k);
	
	ret -> mx = max(ret -> left -> mx, ret -> right -> mx) + ret -> add;
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &h[i].st);
		h[i].nd = i;
	}
	
	for(int i = 1; i <= n; ++i)
		rep[i] = i;
	
	root[n + 1] = build(17);
	sort(h + 1, h + n + 1);
	for(int i = n; i >= 1; --i){
		int pl = h[i].nd;
		int val = ask(root[i + 1], pl + 1, pl + 1) + 1;
		
		if(is[pl - 1])
			Union(pl - 1, pl);
		if(is[pl + 1])
			Union(pl, pl + 1);

		is[pl] = true;
		root[i] = add(root[i + 1], Find(pl), pl, val);
	}
	
	int quest;
	scanf("%d", &quest);
	
	while(quest--){
		int l, r, w;
		scanf("%d %d %d", &l, &r, &w);
		r -= w - 1;
		
		int from = 1, to = n;
		while(from < to){
			int m = (from + to + 1) >> 1;
			if(ask(root[m], l, r) >= w)
				from = m;
			else
				to = m - 1;
		}
		
		printf("%d\n", h[from].st);
	}

	return 0;
}