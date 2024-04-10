#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXD = 5e2 + 5;
const int MAXS = 5e3 + 5;
const int INF = 0x3f3f3f3f;

int D, S;
int dist[MAXD][MAXS];
pii dad[MAXD][MAXS];
int digit[MAXD][MAXS];
queue <pii> Q;

void load() {
	scanf("%d%d", &D, &S);
}

void solve() {
	memset(dist, INF, sizeof dist);
	dist[0][0] = 0;
	Q.push({0, 0});
	
	while (!Q.empty()) {
		pii curr = Q.front();
		Q.pop();
		for (int i = 0; i < 10; i++) {
			int nxt = (10 * curr.first + i) % D;
			int sum = curr.second + i;
			if (sum <= S && dist[nxt][sum] == INF) {
				dist[nxt][sum] = dist[curr.first][curr.second] + 1;
				dad[nxt][sum] = curr;
				digit[nxt][sum] = i;
				Q.push({nxt, sum});
			}
		}
	}
	
	if (dist[0][S] == INF) {
		puts("-1");
		return;
	}
	
	deque <int> ans;
	for (pii p = {0, S}; p != pii(0, 0); p = dad[p.first][p.second])
		ans.push_front(digit[p.first][p.second]);
	
	for (auto it : ans)
		printf("%d", it);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}