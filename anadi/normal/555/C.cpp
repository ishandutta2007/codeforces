#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int K = 1 << 30;

struct ver{
	int val;
	int l, r;
	
	ver(int _val = 0, int _l = 0, int _r = 0){
		val = _val;
		l = _l;
		r = _r;
	}
};

int n, q;
set <PII> S;
ver tree[N * 40][2];
int licz = 1;

int sprawdz(int v, int a, int b, int d, int t){
//	printf("%d :: %d %d :: %d %d\n", v, a, b, d, t);
	if(a == b)
		return tree[v][t].val;

	int m = (a + b) / 2;
	if(d <= m){
		if(tree[v][t].l == 0)
			return tree[v][t].val;
		return max(tree[v][t].val, sprawdz(tree[v][t].l, a, m, d, t));
	}
	else{
		if(tree[v][t].r == 0)
			return tree[v][t].val;
		return max(tree[v][t].val, sprawdz(tree[v][t].r, m + 1, b, d, t));
	}
}

int val(int x, int t){
	return sprawdz(1, 0, K - 1, x, t);
}

void create(int v, int t, int type){
	if(type == 0)
		tree[v][t].l = ++licz;
	else
		tree[v][t].r = ++licz;
}

void akt(int v, int p, int k, int a, int b, int val, int t){
	if(p >= a && k <= b){
		tree[v][t].val = max(tree[v][t].val, val);
//		printf("%d :: %d %d :: %d %d :: %d %d\n", v, p, k, a, b, val, t);
		return;
	}
	
	int m = (p + k) / 2;
	if(a <= m){
		if(tree[v][t].l == 0)
			create(v, t, 0);
		akt(tree[v][t].l, p, m, a, b, val, t);
	}
	
	if(b > m){
		if(tree[v][t].r == 0)
			create(v, t, 1);
		akt(tree[v][t].r, m + 1, k, a, b, val, t);
	}
}

int main(){
	scanf("%d %d", &n, &q);
	while(q--){
		int a, b;
		char c;
		scanf("%d %d", &a, &b);
		scanf(" %c", &c);
		if(S.find(mp(a, b)) != S.end()){
			puts("0");
			continue;
		}
		
		if(c == 'L'){
			int r = val(b, 0);
			printf("%d\n", a - r);
			akt(1, 0, K - 1, r, a, b, 1);
		}
		
		if(c == 'U'){
			int r = val(a, 1);
			printf("%d\n", b - r);
			akt(1, 0, K - 1, r, b, a, 0);
		}
		
		S.insert(mp(a, b));
	}
	return 0;
}