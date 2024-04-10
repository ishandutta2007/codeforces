#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e6 + 5;
const int LOG = 21;
const int MOD = 1e9 + 7;

int N, M, K;
vector <pii> adj[MAXN], inv[MAXN];
int anc[MAXN][LOG];
int units[MAXN];
int dist[MAXN];
bool bio[MAXN];
int ans[MAXN];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

void subdivide(const vector <int> &v, int a, int b) {
	vector <int> s = {a};
	for (int i = 1; i < v.size(); i++)
		s.push_back(++N);
	
	vector <int> t = s;
	t.erase(t.begin());
	t.push_back(b);
	
	for (int i = 0; i < v.size(); i++) 
		adj[s[i]].push_back({t[i], v[i]});
}

void load() {
	scanf("%d%d", &N, &M);
	K = N;
	for (int i = 1; i <= M; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		vector <int> digits;
		for (int num = i; num; num /= 10)
			digits.push_back(num % 10);
		reverse(digits.begin(), digits.end());
		subdivide(digits, x, y);
		subdivide(digits, y, x);
	}
}

bool cmp(int x, int y) {
	for (int i = LOG - 1; i >= 0; i--)
		if (ans[anc[x][i]] != ans[anc[y][i]]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	return units[x] < units[y];
}

void dfs(int x) {
	if (bio[x])
		return;
	bio[x] = true;
	for (auto it : inv[x])
		dfs(it.first);
	
	if (inv[x].empty())
		return;
	
	pii opt = inv[x][0];
	for (auto it : inv[x]) 	
		if (cmp(it.first, opt.first) || (!cmp(opt.first, it.first) && it.second < opt.second)) 
			opt = it;
	
	ans[x] = add(mul(ans[opt.first], 10), opt.second);
	units[x] = opt.second;
	
	anc[x][0] = opt.first;
	for (int i = 1; i < LOG; i++)
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
}

void solve() {
	memset(dist, -1, sizeof dist);
	
	queue <int> Q;
	dist[1] = 0;
	Q.push(1);
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (auto it : adj[x])
			if (dist[it.first] == -1) {
				dist[it.first] = dist[x] + 1;
				Q.push(it.first);
			}
	}
	
	for (int i = 1; i <= N; i++)
		for (auto it : adj[i])
			if (dist[it.first] == dist[i] + 1) 
				inv[it.first].push_back({i, it.second});
			
	for (int i = 1; i <= N; i++)
		dfs(i);
		
	for (int i = 2; i <= K; i++)
		printf("%d\n", ans[i]);
}

int main() {
	load();
	solve();
	return 0;
}