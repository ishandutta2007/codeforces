#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, C, D;
int b[MAXN], p[MAXN];
char t[MAXN];
vector <pii> vals[2];
int pref[MAXN];

void load() {
	scanf("%d%d%d", &N, &C, &D);
	for (int i = 0; i < N; i++)
		scanf("%d%d %c", b + i, p + i, t + i);
}

int solve() {
	int mx1 = 0, mx2 = 0;
	for (int i = 0; i < N; i++) {
		if (t[i] == 'C' && p[i] <= C)
			mx1 = max(mx1, b[i]);
		if (t[i] == 'D' && p[i] <= D)
			mx2 = max(mx2, b[i]);
	}
	
	int sol = mx1 && mx2 ? mx1 + mx2 : 0;
	for (int i = 0; i < N; i++)
		vals[t[i] == 'C'].push_back({p[i], b[i]});
	
	for (int i = 0; i < 2; i++) {
		sort(vals[i].begin(), vals[i].end());
		for (int j = 0; j < vals[i].size(); j++) {
			pref[j] = vals[i][j].second;
			if (j)
				pref[j] = max(pref[j], pref[j - 1]);
		}
		for (int j = 1; j < vals[i].size(); j++) {
			int pos = min(j - 1, (int)(lower_bound(vals[i].begin(), vals[i].end(), pii((i ? C : D) - vals[i][j].first + 1, 0)) - vals[i].begin() - 1));
			if (pos >= 0)
				sol = max(sol, vals[i][j].second + pref[pos]);
		}
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}