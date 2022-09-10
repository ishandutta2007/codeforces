#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int T = 1 << 18;

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m;
int in[N];

int ans[N];
vector <PII> req[N];

PII order[N];
int tree[T + T];

void add(int v) {
	v += T;
	while(v) {
		tree[v]++;
		v >>= 1;
	}
}

int ask(int v) {
	int cur = 1;
	while(cur < T) {
		cur *= 2;
		if(v > tree[cur]) {
			v -= tree[cur];
			++cur;			
		}
	}
	
	return cur - T;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);
		order[i] = {in[i], i};
	}
	
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) {
		int k, p;
		scanf("%d %d", &k, &p);
		req[k].push_back({p, i});
	}
	
	sort(order + 1, order + n + 1, [](const PII &a, const PII &b){
		if(a.st == b.st)
			return a.nd < b.nd;
		return a.st > b.st;
	});
	
	for(int i = 1; i <= n; ++i) {
		add(order[i].nd);
		for(auto [v, id]: req[i])
			ans[id] = in[ask(v)];
	}
	
	for(int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}