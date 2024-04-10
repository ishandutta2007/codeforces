#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int>E[101000], L[101000];
long long D[101000][2];
int Path[101000][2];
struct AA {
	long long d;
	int a;
	int pv;
	bool operator <(const AA &p)const {
		return d > p.d;
	}
	bool operator ==(const AA &p)const {
		return d == p.d&&a == p.a&&pv == p.pv;
	}
};
int n, m, K, Q;
priority_queue<AA>PQ;
vector<int>G[101000];
struct Query {
	int a, b;
}QQ[301000];
long long Res[301000];
void Add(int a, long long d, int pv) {
	if (D[a][0] > d) {
		if (Path[a][0] == pv) {
			D[a][0] = d;
		}
		else {
			D[a][1] = D[a][0], Path[a][1] = Path[a][0];
			D[a][0] = d, Path[a][0] = pv;
		}
		PQ.push({ d,a,pv });
	}
	if (Path[a][0] != pv && D[a][1] > d) {
		D[a][1] = d;
		Path[a][1] = pv;
		PQ.push({ d,a,pv });
	}
}
struct Edge {
	int a, b;
	long long c;
	bool operator <(const Edge &p)const {
		return c < p.c;
	}
};
vector<Edge>Ed;
void Make(int a, int b, int c) {
	if (a > b)return;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (Path[a][i] == Path[b][j])continue;
			Ed.push_back({ Path[a][i],Path[b][j],D[a][i] + D[b][j] + c });
		}
	}
}
int UF[101000];
vector<int>Z[101000];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Merge(int a, int b, long long c) {
	a = Find(a), b = Find(b);
	if (a == b)return;
	if (Z[a].size() < Z[b].size())swap(a, b);
	for (auto &t : Z[b]) {
		for (auto &q : G[t]) {
			int l = QQ[q].a + QQ[q].b - t;
			if (Find(l) == a) {
				Res[q] = c;
			}
		}
		Z[a].push_back(t);
	}
	UF[b] = a;
}
int main() {
	int i, a, b, c;
	scanf("%d%d%d%d", &n, &m, &K, &Q);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(c);
		L[b].push_back(c);
	}
	for (i = 1; i <= n; i++)D[i][0] = D[i][1] = 1e18;
	for (i = 1; i <= K; i++) {
		Add(i, 0, i);
	}
	while (!PQ.empty()) {
		AA tp = PQ.top();
		int a = tp.a;
		AA t1 = { D[a][0],a, Path[a][0] };
		AA t2 = { D[a][1],a, Path[a][1] };
		PQ.pop();
		if (tp == t1 || tp == t2) {
			for (int i = 0; i < E[a].size(); i++) {
				Add(E[a][i], tp.d + L[a][i], tp.pv);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		UF[i] = i;
		Z[i].push_back(i);
		Ed.push_back({ Path[i][0],Path[i][1],D[i][0] + D[i][1] });
	}
	for (i = 1; i <= n; i++) {
		for (int j = 0; j < E[i].size(); j++) {
			Make(i, E[i][j], L[i][j]);
		}
	}
	sort(Ed.begin(), Ed.end());
	for (i = 1; i <= Q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		QQ[i] = { a,b };
		G[a].push_back(i);
		G[b].push_back(i);
	}
	for (auto &t : Ed) {
		Merge(t.a, t.b, t.c);
	}
	for (i = 1; i <= Q; i++)printf("%lld\n", Res[i]);
}