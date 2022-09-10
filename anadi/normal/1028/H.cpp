#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int T = 1 << 18;

const int Q = 1e6 + 7;
const int V = 5e6 + 1e5;

const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, q;
int in[N];
int iloczyn[N];
int tree1[15][T + T + 7];
int tree2[15][T + T + 7];

int sito[V];
int last[V][10];

vector <int> base(int a){
	vector <int> ret;
	while(a > 1){
		int d = sito[a], cnt = 0;
		while(a%d == 0){
			a /= d;
			cnt ^= 1;
		}

		if(cnt)
			ret.push_back(d);
	}
	
	return ret;
}

void add1(int t, int x, int v){
	x += T;
	while(x){
		if(tree1[t][x] <= v)
			break;

		tree1[t][x] = min(tree1[t][x], v);
		x >>= 1;
	}
}

void add2(int t, int x, int v){
	x += T;
	while(x){
		if(v <= tree2[t][x])
			break;

		tree2[t][x] = max(tree2[t][x], v);
		x >>= 1;
	}
}

int ask1(int t, int l, int r){
	int ret = n + 1;
	l += T, r += T;
	
	while(l < r){
		if(l & 1)
			ret = min(ret, tree1[t][l]);
		if(!(r & 1))
			ret = min(ret, tree1[t][r]);
		
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	
	if(l == r)
		ret = min(ret, tree1[t][l]);
	return ret;
}


int ask2(int t, int l, int r){
	int ret = 0;
	l += T, r += T;
	
	while(l < r){
		if(l & 1)
			ret = max(ret, tree2[t][l]);
		if(!(r & 1))
			ret = max(ret, tree2[t][r]);
		
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	
	if(l == r)
		ret = max(ret, tree2[t][l]);
	return ret;
}

void go1(int r, int p, int il){
	for(int i = 0; i < 8; ++i)
		add1(r + i, p, last[il][i]);
	last[il][r] = p;
}

void go2(int r, int p, int il){
	for(int i = 0; i < 8; ++i)
		add2(r + i, p, last[il][i]);
	last[il][r] = p;
}

int main(){
	for(int i = 2; i * i < V; ++i)
		if(sito[i] == 0){
			sito[i] = i;
			for(int j = i * i; j < V; j += i)
				sito[j] = i;
		}
	
	for(int i = 1; i < V; ++i)
		if(sito[i] == 0)
			sito[i] = i;

	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);

	for(int i = 1; i < V; ++i)
		for(int j = 0; j < 8; ++j)
			last[i][j] = n + 1;
	
	for(int i = 1; i < T + T; ++i)
		for(int j = 0; j < 15; ++j)
			tree1[j][i] = n + 1;

	for(int i = n; i >= 1; --i){
		vector <int> cur = base(in[i]);
		int t = (1 << int(cur.size())) - 1;
		iloczyn[0] = 1;
		
		go1(cur.size(), i, 1);
		for(int j = 1; j <= t; ++j){
			int bit = __builtin_ctz(j);
			iloczyn[j] = iloczyn[j ^ (1 << bit)] * cur[bit];
			
			go1(__builtin_popcount(j ^ t), i, iloczyn[j]);
			last[iloczyn[j]][__builtin_popcount(j ^ t)] = i;
		}
	}
	
	for(int i = 1; i < V; ++i)
		for(int j = 0; j < 8; ++j)
			last[i][j] = 0;
	
	for(int i = 1; i <= n; ++i){
		vector <int> cur = base(in[i]);
		int t = (1 << int(cur.size())) - 1;
		iloczyn[0] = 1;
		
		go2(cur.size(), i, 1);
		for(int j = 1; j <= t; ++j){
			int bit = __builtin_ctz(j);
			iloczyn[j] = iloczyn[j ^ (1 << bit)] * cur[bit];

			go2(__builtin_popcount(j ^ t), i, iloczyn[j]);
			last[iloczyn[j]][__builtin_popcount(j ^ t)] = i;
		}		
	}
	
	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);
		
		for(int i = 0; i < 15; ++i){
			if(ask1(i, l, r) <= r){
				printf("%d\n", i);
				break;
			}
			
			if(l <= ask2(i, l, r)){
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}