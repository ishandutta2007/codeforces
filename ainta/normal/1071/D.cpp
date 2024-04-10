#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
vector<int>P;
vector<int>T;
map<vector<int>, int>Map;
vector<int>E[1010000];
vector<int>G[5010];
long long INF = 1e12;
vector<int>VV;
int cnt, Num[1010000], D[5010], Q[5010], CT[1010000], Res[5010][5010];
void Go(long long a, int pv, int c) {
	Map[T] = ++cnt;
	if (a <= 1000000) {
		VV.push_back(cnt);
	}
	int i;
	for (i = 1; i <= c; i++) {
		a *= P[pv];
		if (a > INF)return;
		T.push_back(i);
		Go(a, pv+1, i);
		T.pop_back();
	}
}
void Add_Edge(int a, int b) {
	G[a].push_back(b);
	G[b].push_back(a);
}
int cnt2;
void BFS(int a) {
	int i, head = 0 , tail = 0;
	for (i = 1; i <= cnt+cnt2; i++)D[i] = 1e9;
	D[a] = 0, Q[++tail] = a;
	while (head < tail) {
		int x = Q[++head];
		for (auto &y : G[x]) {
			if (D[y] > D[x] + 1) {
				D[y] = D[x] + 1;
				Q[++tail] = y;
			}
		}
	}
	for (auto &aa : VV)for (auto &bb : VV) {
		Res[aa][bb] = min(Res[aa][bb], D[aa] + D[bb]-2);
	}
}
map<int, int>Map2;
int main() {
	int i, j;
	for (i = 2; i <= 1000; i++) {
		for (j = 2; j*j <= i; j++)if (i%j == 0)break;
		if (j*j > i)P.push_back(i);
	}
	Go(1, 0, 50);
	for (i = 2; i <= 1000000; i++) {
		if (!E[i].empty())continue;
		for (j = i; j <= 1000000; j += i) {
			E[j].push_back(i);
		}
	}
	for (i = 1; i <= 1000000; i++) {
		vector<int>TP;
		for (auto &t : E[i]) {
			int x = i, c = 0;
			while (x%t == 0) {
				c++;
				x /= t;
			}
			TP.push_back(c);
		}
		sort(TP.begin(), TP.end());
		reverse(TP.begin(), TP.end());
		Num[i] = Map[TP];
	}
	for (i = 1; i <= cnt; i++)for (j = 1; j <= cnt; j++)Res[i][j] = 1e9;
	for (auto &t : Map) {
		vector<int>TP = t.first;
		for (i = 0; i < TP.size(); i++) {
			vector<int>TT = TP;
			TT[i]++;
			sort(TT.begin(), TT.end());
			reverse(TT.begin(), TT.end());
			if (Map.count(TT)) {
				Add_Edge(t.second, Map[TT]);
			}
		}
		vector<int>TT = TP;
		TT.push_back(1);
		sort(TT.begin(), TT.end());
		reverse(TT.begin(), TT.end());
		if (Map.count(TT)) {
			Add_Edge(t.second, Map[TT]);
		}
		int ct = 1;
		for (i = 0; i < TP.size(); i++) {
			ct *= TP[i] + 1;
		}
		if (!Map2.count(ct)) {
			Map2[ct] = ++cnt2;
		}
		CT[t.second] = Map2[ct];
		G[cnt + CT[t.second]].push_back(t.second);
	}
	for (i = cnt+1; i <= cnt+cnt2; i++) {
		BFS(i);
	}
	int TC, a, b;
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", Res[Num[a]][Num[b]]);
	}
}