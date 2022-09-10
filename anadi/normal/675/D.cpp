#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int mxn = 1e6 + 7;

#define PII pair <int, int>
#define mp make_pair
#define st first
#define nd second

int n;
PII T[mxn];
PII P[mxn];
int tree[mxn];
map <int, int> M;
int K = 1;

bool cmp(PII a, PII b){
	return a.nd < b.nd;
}

int value(int x){
	x += K - 1;
	int res = 0;
	while(x > 0){
		res = max(res, tree[x]);
		x /= 2;
	}
	
	return res;
}

void akt(int from, int to, int val){
	from += K - 1;
	to += K - 1;
	
	while(from < to){
		if(from%2 == 1){
			tree[from] = val;
			++from;
		}
		if(to%2 == 0){
			tree[to] = val;
			--to;
		}
		
		to /= 2;
		from /= 2;
	}
	
	if(from == to)
		tree[from] = val;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &T[i].st);
		T[i].nd = i;
	}

	while(K < n)
		K *= 2;

	sort(T + 1, T + n + 1);
	for(int i = 1; i <= n; ++i){
		M[i] = T[i].st;
		T[i].st = i;
	}
	sort(T + 1, T + n + 1, cmp);
	
	akt(1, n, 1);
	P[1].st = 1;
	P[1].nd = n;
	for(int i = 2; i <= n; ++i){
		int parent = value(T[i].st);
		printf("%d ", M[T[parent].st]);
		if(T[i].st < T[parent].st)
			P[i] = mp(P[parent].st, T[parent].st);
		else
			P[i] = mp(T[parent].st, P[parent].nd);
		
		akt(P[i].st, P[i].nd, i);
	}

	return 0;
}