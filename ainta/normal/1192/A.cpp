#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#define N_ 1510000
#define pii pair<int,int>
using namespace std;

int dx[8] = { -1,-1,-1,0,1,1,1,0 }, dy[8] = { 1,0,-1,-1,-1,0,1,1 };

int UF[N_];
map<pii, int>Map, Map2;

int n;

struct point {
	int x, y;
}P[N_];

vector<int>E[N_], G[N_];

int Num[N_], cnt;
set<pii>Set;

void DFS(int a) {
	Num[a] = ++cnt;
	for (auto &x : E[a]) {
		if (!Num[x]) DFS(x);
	}
}


int vis[N_], blocked[N_], pos[N_], w[N_][9];
int BN[N_], ReNum[N_], Q[N_], head, tail;

int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Merge(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b)UF[a] = b;
}

priority_queue<int>PQ;
void BFS() {
	while (head < tail) {
		int x = Q[++head];
		for (auto &t : G[x]) {
			if (vis[t])continue;
			if (!blocked[t]) {
				Q[++tail] = t;
				vis[t] = 1;
			}
			else if (!pos[t]) {
				pos[t] = 1;
				PQ.push(ReNum[t]);
			}
		}
	}
}

int main() {
	int i, j, sub;
	scanf("%d%d", &n, &sub);
	for (i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x,&y);
		P[i] = { x,y };
		Map[{x, y}] = i;
		Set.insert({ x,y });
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 8; j++) {
			int tx = P[i].x + dx[j], ty = P[i].y + dy[j];
			Set.insert({ tx,ty });
			if (Map.count({ tx,ty })) {
				E[i].push_back(Map[{tx, ty}]);
			}
		}
	}
	DFS(1);
	if (cnt != n) {
		puts("NO");
		return 0;
	}
	int c = 0;
	for (auto &t : Set) {
		Map2[t] = ++c;
	}
	for (auto &t : Set) {
		int a = Map2[t];
		for (j = 1; j < 8; j+=2) {
			int tx = t.first + dx[j], ty = t.second + dy[j];
			if (Map2.count({ tx, ty })) {
				G[a].push_back(Map2[{tx, ty}]);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 8; j++) {
			int tx = P[i].x + dx[j], ty = P[i].y + dy[j];
			w[i][j] = Map2[{tx, ty}];
		}
	}

	for (i = 1; i <= n; i++) {
		BN[i] = Map2[{P[i].x, P[i].y}];
		ReNum[BN[i]] = i;
		blocked[BN[i]] = 1;
	}

	for (i = 1; i <= c; i++)UF[i] = i;
	for (i = 1; i <= c; i++){
		for (auto &x : G[i]) {
			if (!blocked[i] && !blocked[x])Merge(i, x);
		}
	}
	Q[++tail] = 1;
	vis[1] = 1;
	BFS();
	vector<int>Res;
	while (!PQ.empty()) {
		int a = PQ.top();
		PQ.pop();
		int x = BN[a], ck = 0;
		if (!pos[x] || !blocked[x])continue;
		int pv = -1;
		for (i = 0; i < 8; i++) {
			int t = w[a][i];
			if (blocked[t])pv = i;
		}
		if (pv != -1) {
			int TP[9], cc = 0;
			for (i = 0; i < 8; i++)TP[i] = 0;
			for (i = 0; i < 8; i++) {
				int t = w[a][(pv+i)%8];
				if (blocked[t]) cc++;
				else TP[(pv+i)%8] = cc;
			}
			for (i = 1; i < 8; i += 2) {
				for (int j = i+2; j < 8; j += 2) {
					int t1 = w[a][i], t2 = w[a][j];
					if (!blocked[t1] && !blocked[t2] && TP[i] != TP[j] && Find(t1) == Find(t2))ck = 1;
				}
			}
			if (ck)continue;
		}

		Res.push_back(a);
		blocked[x] = 0;
		Q[++tail] = x;
		vis[x] = 1;
		BFS();
		for (auto &z : G[x]) {
			if (!blocked[z])Merge(x, z);
		}
		for (auto &z : E[a]) {
			PQ.push(z);
		}
	}
	puts("YES");
	reverse(Res.begin(), Res.end());
	for (auto &t : Res)printf("%d\n", t);
}