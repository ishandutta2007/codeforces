#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> pii;

const int MAXN = 1e5 + 5;
const int LOG = 18;

int N, L;
ll T;
int w[MAXN];
vector <int> ch[MAXN];
int anc[MAXN][LOG];
int dep[MAXN];
ll sum[MAXN];
pii curr[MAXN];

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (dep[lhs] != dep[rhs])
			return dep[lhs] > dep[rhs];
		return lhs > rhs;
	}
};

set <int, cmp> S;

void load() {
	scanf("%d%d%lld", &N, &L, &T);
	for (int i = 1; i <= N; i++)
		scanf("%d", w + i);
	for (int i = 2; i <= N; i++) {
		int x;
		scanf("%d", &x);
		ch[x].push_back(i);
		anc[i][0] = x;
	}
}

void dfs(int x, int d, ll s) {
	s += w[x];
	dep[x] = d;
	sum[x] = s;
	for (auto it : ch[x])
		dfs(it, d + 1, s);
}

inline bool good(pii arg) {
	return arg.first <= L && arg.second <= T;
}

pii get(int x, int y) {
	return {dep[x] - dep[y] + 1, sum[x] - sum[y] + w[y]};
}

pii operator +(pii a, pii b) {
	return {a.first + b.first, a.second + b.second};
}

void operator +=(pii &a, pii b) {
	a = a + b;
}

int reach(int x) {
	int y = x;
	for (int i = LOG - 1; i >= 0; i--)
		if (good(curr[x] + get(anc[x][0], anc[y][i])))
			y = anc[y][i];
	return y;
}

ll solve() {
	for (int i = 1; i <= N; i++)
		if (w[i] > T)
			return -1;
			
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	
	dfs(1, 0, 0);
	
	for (int i = 1; i <= N; i++) {
		curr[i] = {1, w[i]};
		S.insert(i);
	}
	
	int sol = 0;
	while (!S.empty()) {
		int x = *S.begin();
		if (x == 1) {
			sol++;
			break;
		}
		int dad = anc[x][0];
		int opt = -1, low = -1;
		for (auto it : ch[dad]) {
			int tmp = reach(it);
			if (opt == -1 || dep[tmp] < dep[low]) { 
				opt = it;
				low = tmp;
			}
			S.erase(it);
		}
		sol += (int)ch[dad].size() - 1;
		if (low == opt)
			sol++;
		else
			curr[dad] += curr[opt];
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}