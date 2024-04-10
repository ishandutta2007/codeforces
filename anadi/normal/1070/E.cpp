#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 2e5 + 7;

int n, m;
LL Time;

int in[N];
int rv[N];

int T;
int sum[3 * N];
LL tree[3 * N];
vector <int> req[N];

void renumber(){
	vector <PII> V;
	V.push_back({0, 0});

	for(int i = 1; i <= n; ++i)
		V.push_back({in[i], i});
	sort(V.begin(), V.end());
	
	int cnt = 0;
	for(int i = 1; i < V.size(); ++i){
		if(V[i].st != V[i - 1].st)
			++cnt;
		
		rv[cnt] = V[i].st;
		in[V[i].nd] = cnt;
	}
}

void add(int u, int v){
	u += T;
	while(u){
		sum[u] += 1;
		tree[u] += v;
		u >>= 1;
	}
}

LL query(int from, int to){
	LL ret = 0;
	from += T, to += T;
	while(from < to){
		if(from & 1)
			ret += tree[from];
		if(!(to & 1))
			ret += tree[to];
			
		from = (from + 1) >> 1;
		to = (to - 1) >> 1;
	}
	
	if(from == to)
		ret += tree[from];
	return ret;
}

int get(int v){
	int cur = 1;
	while(cur < T){
		cur += cur;
		if(sum[cur] < v)
			v -= sum[cur], ++cur;
	}
	
	return cur - T;
}

bool ok(int a){
	int t = (a - 1)%m + 1; int pl = get(a - t);
	return 2 * query(1, pl) + query(pl + 1, get(a)) <= Time;
}

int ask(){
	int p = 0, k = sum[1];
	while(p < k){
		int m = (p + k + 1) >> 1;
		if(ok(m))
			p = m;
		else
			k = m - 1;
	}
	
	return p;
}

void solve(){
	scanf("%d %d %lld", &n, &m, &Time);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	renumber();
	
	for(int i = 1; i <= n; ++i)
		req[in[i]].push_back(i);
	
	T = 1;
	while(T <= n)
		T *= 2;
	
	int res = 0, opt = 1;
	for(int i = 1; i <= n; ++i){
		for(int v: req[i])
			add(v, rv[i]);
		req[i].clear();
		
		int ans = ask();
		if(ans > res)
			res = ans, opt = rv[i];
	}
	
	printf("%d %d\n", res, opt);
	for(int i = 0; i < 2 * T; ++i)
		tree[i] = sum[i] = 0;
}

int main(){
	int quests;
	scanf("%d", &quests);
	
	while(quests--)
		solve();
	return 0;
}