#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 6005;

int N;
int r[MAXN];
vector <int> E[MAXN];
short dp_inc[MAXN][MAXN];
short dp_dec[MAXN][MAXN];
short curr[MAXN][MAXN];
short mx1[MAXN], mx2[MAXN];
vector <int> comp;
short sol;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)	
		scanf("%d", r + i);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

inline void update(short &ref, short val) {
	ref = max(ref, val);
}

void dfs(int x, int p) {
	for (int i = 1; i <= N; i++) {
		dp_dec[x][i] = i >= r[x];
		dp_inc[x][i] = i <= r[x];
	}
	
	for (int nxt : E[x])
		if (nxt != p)
			dfs(nxt, x);
	
	for (int i = 1; i <= N; i++)
		mx1[i] = mx2[i] = 1;
		
	for (int nxt : E[x]) 
		if (nxt != p) 
			for (int i = 1; i <= N; i++) {
				short tmp = dp_dec[nxt][i];
				if (i >= r[x])
					update(tmp, dp_dec[nxt][r[x] - 1] + 1);
				if (tmp >= mx1[i]) {
					mx2[i] = mx1[i];
					mx1[i] = tmp;
				}
				else if (tmp > mx2[i])
					mx2[i] = tmp;
				update(dp_dec[x][i], tmp);
				curr[nxt][i] = tmp;
			}
		
	for (int nxt : E[x])
		if (nxt != p) 
			for (int i = 1; i <= N + 1; i++) {
				short tmp = dp_inc[nxt][i];
				update(sol, tmp + (curr[nxt][i - 1] == mx1[i - 1] ? mx2[i - 1] : mx1[i - 1]));
				if (i <= r[x])
					update(tmp, dp_inc[nxt][r[x] + 1] + 1);
				update(dp_inc[x][i], tmp);
			}
}

int solve() {
	for (int i = 1; i <= N; i++)
		comp.push_back(r[i]);
	sort(comp.begin(), comp.end());
	for (int i = 1; i <= N; i++)
		r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin() + 1;
		
	dfs(1, 0);	
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			update(sol, dp_dec[i][j]);
			update(sol, dp_inc[i][j]);
		}
	
	return (int)sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}