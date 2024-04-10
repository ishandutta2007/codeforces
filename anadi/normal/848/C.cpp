#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int treeSize = 1 << 17;
const int T = 2 * treeSize + 9;

const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, q;
int ss = 2000;
int tree[55][T][2];

int cur[N];
int last[N];
int nast[N];
set <int> S[N];

void dodaj(int t, int x, int val, int flag){
	x += treeSize;
	tree[t][x][flag] += val;
	while(x > 1){
		x /= 2;
		tree[t][x][flag] += val;
	}
}

void change(int pos, int ost, int pop, int flag){
	dodaj(pos / ss, ost, -pos, flag);
	dodaj(pos / ss, pop, pos, flag);
}

void add(int val, int pos){
	auto it = S[val].lower_bound(pos);
	auto it2 = it;
	
	int nP = n + 1, pP = 0;
	if(it != S[val].end())
		nP = *it;
	if(it2 != S[val].begin())
		--it2, pP = *it2;

	last[nP] = pos, nast[pP] = pos;
	last[pos] = pP, nast[pos] = nP;
	
	if(pP != 0)
		change(pP, nP, pos, 0);
	if(nP != n + 1)
		change(nP, pP, pos, 1);
	
	cur[pos] = val;
	S[val].insert(pos);
	dodaj(pos / ss, nP, pos, 0);
	dodaj(pos / ss, pP, pos, 1);	
}

void destroy(int val, int pos){
	S[val].erase(pos);
	auto it = S[val].lower_bound(pos);
	
	int nP = n + 1, pP = 0;
	if(it != S[val].end())
		nP = *it;
	if(it != S[val].begin())
		--it, pP = *it;
	last[nP] = pP, nast[pP] = nP;
	
	if(pP != 0)
		change(pP, pos, nP, 0);
	if(nP != n + 1)
		change(nP, pos, pP, 1);
	
	dodaj(pos / ss, nP, -pos, 0);
	dodaj(pos / ss, pP, -pos, 1);
}

void update(int pos, int val){
	destroy(cur[pos], pos);
	add(val, pos);
}

int ask(int t, int p, int k, int flag){
	int res = 0;
	p += treeSize, k += treeSize;
	
	while(p < k){
		if(p & 1)
			res += tree[t][p][flag];
		if(!(k & 1))
			res += tree[t][k][flag];
		
		p = (p + 1) >> 1;
		k = (k - 1) >> 1;
	}
	
	if(p == k)
		res += tree[t][p][flag];
	return res;
}

LL getAns(int p, int k){
	int sP = p / ss;
	int sK = k / ss;
	
	LL res = 0LL;
	for(int i = sP + 1; i < sK; ++i)
		res += ask(i, k + 1, n + 1, 0) - ask(i, 0, p - 1, 1);
	
	int x = p, y = k;
	while(x / ss == sP && x <= k){
		if(nast[x] > k)
			res += x;
		if(last[x] < p)
			res -= x;
		++x;
	}
	
	while(y / ss == sK && y >= x){
		if(nast[y] > k)
			res += y;
		if(last[y] < p)
			res -= y;
		--y;
	}
	
	return res;
}

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &cur[i]);
		add(cur[i], i);
	}
	
	while(q--){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(t == 1)
			update(x, y);
		else
			printf("%lld\n", getAns(x, y));
	}
	
	return 0;
}