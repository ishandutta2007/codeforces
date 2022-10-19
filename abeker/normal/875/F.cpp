#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

struct edge {
	int a, b, c;
	bool operator <(const edge &rhs) const {
		return c > rhs.c;
	}
};

int N, M;
vector <edge> E;
int dad[MAXN], rnk[MAXN];
bool full[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		E.push_back({a, b, w});
	}
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

int join(edge e) {
	int da = find(e.a);
	int db = find(e.b);
	if (full[da] && full[db])
		return 0;
	if (da == db) {
		full[da] = true;
		return e.c;
	}
	if (rnk[da] > rnk[db])
		swap(da, db);
	dad[da] = db;
	rnk[db] += rnk[da] == rnk[db];
	full[db] |= full[da];
	return e.c;
}

int solve() {
	sort(E.begin(), E.end());
	
	for (int i = 1; i <= N; i++)
		dad[i] = i;
			
	int sol = 0;
	for (auto it : E)
		sol += join(it);
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}