#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MOD = 1e9 + 7;

int N;
int x[MAXN], y[MAXN];
vector <int> X, Y;
vector <int> E[2 * MAXN];
int pot[2 * MAXN];
vector <int> comp;
bool bio[2 * MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d%d", x + i, y + i);	
}

int get_x(int val) {
	return lower_bound(X.begin(), X.end(), val) - X.begin();
}

int get_y(int val) {
	return lower_bound(Y.begin(), Y.end(), val) - Y.begin();
}

void add_edge(int x, int y) {
	E[x].push_back(y + N);
	E[y + N].push_back(x);
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

void dfs(int x) {
	bio[x] = true;
	comp.push_back(x);
	for (auto it : E[x])
		if (!bio[it])
			dfs(it);
}

int solve() {
	for (int i = 0; i < N; i++) {
		X.push_back(x[i]);
		Y.push_back(y[i]);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	
	for (int i = 0; i < N; i++)
		add_edge(get_x(x[i]), get_y(y[i]));
	
	pot[0] = 1;
	for (int i = 1; i <= 2 * N; i++)
		pot[i] = mul(pot[i - 1], 2);
		
	int sol = 1;
	for (int i = 0; i < 2 * N; i++) {
		if (bio[i])
			continue;
		comp.clear();
		dfs(i);
		int edges = 0;
		for (auto it : comp)
			edges += E[it].size();
		int tmp = pot[comp.size()]; 
		if (edges < 2 * comp.size())
			tmp = (tmp + MOD - 1) % MOD;
		sol = mul(sol, tmp);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}