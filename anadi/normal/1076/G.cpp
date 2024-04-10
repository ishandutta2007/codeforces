#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int P = 400;
const int G = 600;
const int N = 2e5 + 7;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, q;
int cur[N];

int p;
int idx[N];
int clicked[G];
int group[G][6][2];

int simulate(int l, int r, bool c){
	while(r >= l){
		if(cur[r] ^ c)
			r -= m + 1;
		else
			--r;
	}

	return l - r - 1;
}

void build(int nr){
	int from = max(nr * P - P, 1), to = min(nr * P, n + 1);
	for(int i = from; i < to; ++i)
		cur[i] ^= clicked[nr];
	clicked[nr] = false;
	
	for(int i = 0; i <= m; ++i){
		group[nr][i][0] = simulate(from, to - i - 1, 0);
		group[nr][i][1] = simulate(from, to - i - 1, 1);
	}
}

void change(int l, int r){
	if(idx[l] == idx[r]){
		for(int i = l; i <= r; ++i)
			cur[i] ^= 1;

		build(idx[l]);
		return;
	}
	
	for(int i = idx[l] + 1; i < idx[r]; ++i)
		clicked[i] ^= 1;
	
	for(int i = l; i < idx[l] * P; ++i)
		cur[i] ^= 1;
	build(idx[l]);
	
	for(int i = idx[r] * P - P; i <= r; ++i)
		cur[i] ^= 1;
	build(idx[r]);
}

int ask(int l, int r){
	if(cur[l] == clicked[idx[l]])
		return 1;
	
	if(idx[l] == idx[r]){
		int t = simulate(l + 1, r, clicked[idx[l]]);
		return t == 0 ? 2 : 1;
	}

	int t = simulate(idx[r] * P - P, r, clicked[idx[r]]);
	int curN = idx[r] - 1;
	
	while(curN > idx[l]){
		t = group[curN][t][clicked[curN]];
		--curN;
	}
	
	t = simulate(l + 1, idx[l] * P - t - 1, clicked[idx[l]]);
	return t == 0 ? 2 : 1;
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; ++i){
		LL a;
		scanf("%lld", &a);
		cur[i] = a % 2;
	}
	
	for(int i = 1; i <= n; ++i)
		idx[i] = i / P + 1;
	
	p = idx[n];
	for(int i = 1; i <= p; ++i)
		build(i);
	
	while(q--){
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		
		if(t == 1){
			LL v;
			scanf("%lld", &v);

			if(v % 2 == 1)
				change(l, r);
		}
		else
			printf("%d\n", ask(l, r));
	}

	return 0;
}