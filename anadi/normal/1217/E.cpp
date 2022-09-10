#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 600 * 1000 + 7;
const int T = 1 << 18;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, q;
PII tree[10][N];

void add(int t, int x, int v){
	x += T;
	tree[t][x] = {v, MX};
	
	while(x > 1){
		x >>= 1;
		if(tree[t][x + x].st < tree[t][x + x + 1].st)
			tree[t][x] = {tree[t][x + x].st, min(tree[t][x + x].nd, tree[t][x + x + 1].st)};
		else
			tree[t][x] = {tree[t][x + x + 1].st, min(tree[t][x + x].st, tree[t][x + x + 1].nd)};
	}
}

void update(int p, int v){
	int x = v;
	for(int i = 0; i < 9; ++i){
		if(x % 10 > 0)
			add(i, p, v);
		else
			add(i, p, MX);
		x /= 10;
	}
}

int ask(int t, int from, int to){
	PII ret = {MX, MX};
	from += T, to += T;

	while(from <= to){
		if(from & 1){
			if(tree[t][from].st < ret.st){
				ret.nd = min(ret.st, tree[t][from].nd);
				ret.st = tree[t][from].st;
			}
			else
				ret.nd = min(ret.nd, tree[t][from].st);
		}
		
		if(!(to & 1)){
			if(tree[t][to].st < ret.st){
				ret.nd = min(ret.st, tree[t][to].nd);
				ret.st = tree[t][to].st;
			}
			else
				ret.nd = min(ret.nd, tree[t][to].st);
		}
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(ret.nd == MX)
		return 2 * MX;
	return ret.st + ret.nd;
}

int query(int from, int to){
	int ret = MX + MX;
	for(int i = 0; i < 9; ++i)
		ret = min(ret, ask(i, from, to));
	
	if(ret == MX + MX)
		return -1;
	return ret;
}

int main(){
	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < N; ++j)
			tree[i][j] = {MX, MX};

	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		update(i, x);
	}
	
	while(q--){
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		
		if(t == 1)
			update(a, b);
		else
			printf("%d\n", query(a, b));
	}

	return 0;
}