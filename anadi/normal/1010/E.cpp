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

int n, m, k;
int l[3];
int mn[3], mx[3];

int ans[N];
vector <vector <int> > V[8];
vector <vector <int> > req[8];

void Add(vector <int> cur, int t, int nr){
	if(t == 3){
		V[nr].push_back(cur);
		return;
	}
	
	if(cur[t] <= mx[t])
		Add(cur, t + 1, nr * 2);
	if(mn[t] <= cur[t])
		Add(cur, t + 1, nr * 2 + 1);
}

vector <int> get(int a, int b, int c){
	return vector <int> {a, b, c};
}

int tree[T + T + 7];
void add(int pl, int v){
	pl += T;
	while(pl){
		tree[pl] = min(tree[pl], v);
		pl >>= 1;
	}
}

void add2(int pl, int v){
	pl += T;
	while(pl){
		tree[pl] = max(tree[pl], v);
		pl >>= 1;
	}
}

int ask(int from, int to){
	int ret = T;
	from += T, to += T;
	
	while(from < to){
		if(from & 1)
			ret = min(ret, tree[from]);
		if(!(to & 1))
			ret = min(ret, tree[to]);
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret = min(ret, tree[from]);
	return ret;
}

int ask2(int from, int to){
	int ret = 0;
	from += T, to += T;
	
	while(from < to){
		if(from & 1)
			ret = max(ret, tree[from]);
		if(!(to & 1))
			ret = max(ret, tree[to]);
		
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret = max(ret, tree[from]);
	return ret;
}

void build(int t){
	for(int i = 0; i < T + T; ++i)
		if(t & 1)
			tree[i] = T;
		else
			tree[i] = 0;
	
	sort(V[t].begin(), V[t].end());
	sort(req[t].begin(), req[t].end());
	
	if(t < 4)
		reverse(req[t].begin(), req[t].end());
	else
		reverse(V[t].begin(), V[t].end());
	
	int dir = t < 4 ? 1 : -1;
	for(auto v: req[t]){
		while(V[t].size() && (V[t].back()[0] * dir >= v[0] * dir || (mn[0] <= V[t].back()[0] && V[t].back()[0] <= mx[0]))){
			if(t & 1)
				add(V[t].back()[1], V[t].back()[2]);
			else
				add2(V[t].back()[1], V[t].back()[2]);
			V[t].pop_back();
		}
		
		int from, to;
		if(t & 2)
			from = mn[1], to = max(mx[1], v[1]);
		else
			from = min(mn[1], v[1]), to = mx[1];
		
		if(t & 1)
			ans[v[3]] = ask(from, to) <= max(mx[2], v[2]);
		else
			ans[v[3]] = min(mn[2], v[2]) <= ask2(from, to);
	}
}

int main(){
	scanf("%d %d %d", &l[0], &l[1], &l[2]);
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i < 3; ++i)
		mn[i] = l[i], mx[i] = 1;
	
	for(int i = 1; i <= n; ++i){
		int in[3];
		scanf("%d %d %d", &in[0], &in[1], &in[2]);
		
		for(int j = 0; j < 3; ++j)
			mn[j] = min(mn[j], in[j]),
			mx[j] = max(mx[j], in[j]);
	}
	
	for(int i = 1; i <= m; ++i){
		int in[3];
		scanf("%d %d %d", &in[0], &in[1], &in[2]);
		
		bool inside = true;
		for(int j = 0; j < 3; ++j)
			inside &= mn[j] <= in[j] && in[j] <= mx[j];
		
		if(inside){
			puts("INCORRECT");
			return 0;
		}
		
		Add(get(in[0], in[1], in[2]), 0, 0);
	}
	
	puts("CORRECT");
	for(int i = 1; i <= k; ++i){
		int in[3];
		scanf("%d %d %d", &in[0], &in[1], &in[2]);
		
		bool inside = true;
		for(int j = 0; j < 3; ++j)
			inside &= mn[j] <= in[j] && in[j] <= mx[j];
		
		if(inside){
			ans[i] = -1;
			continue;
		}
		
		int reqNr = 0;
		for(int j = 0; j < 3; ++j)
			reqNr = reqNr * 2 + (in[j] > mx[j]);
		
//		printf("%d\n", reqNr);
		req[reqNr].push_back(get(in[0], in[1], in[2]));
		req[reqNr].back().push_back(i);
	}
	
	for(int i = 0; i < 8; ++i)
		build(i);
	
	for(int i = 1; i <= k; ++i)
		if(ans[i] == -1)
			puts("OPEN");
		else if(ans[i] == 0)
			puts("UNKNOWN");
		else
			puts("CLOSED");
	return 0;
}