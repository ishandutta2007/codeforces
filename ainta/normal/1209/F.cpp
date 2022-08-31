#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
int n, m, D1[101000];
vector<int>E1[101000], L1[101000];
void Add_Edge1(int a, int b, int c) {
	E1[a].push_back(b);
	L1[a].push_back(c);
	E1[b].push_back(a);
	L1[b].push_back(c);
}
priority_queue<pii>PQ;
void Put1(int a, int l) {
	if (D1[a] <= l)return;
	D1[a] = l;
	PQ.push({ -l,a });
}
void Dijk1(int a) {
	int i;
	for (i = 1; i <= n; i++)D1[i] = 1e9;
	Put1(a, 0);
	while (!PQ.empty()) {
		pii tp = PQ.top();
		PQ.pop();
		int x = tp.second;
		if (-tp.first != D1[x])continue;
		for (int i = 0; i < E1[x].size(); i++) {
			Put1(E1[x][i], D1[x] + L1[x][i]);
		}
	}
}
struct Edge {
	int a, b, c;
}Ed[101000];
int DD[701000];
vector<int>E[701000], F[701000], FL[701000], L[701000], G[701000];
int Q[701000], head, tail, Rank[701000];
pii Path[701000];
long long Ans[701000], Mod = 1000000007;
void Add_Edge2(int a, int b, int c) {
	E[a].push_back(b);
	L[a].push_back(c);
	F[b].push_back(a);
	FL[b].push_back(c);
}
struct AA {
	int pr, c;
	bool operator < (const AA &p)const {
		return pr != p.pr ? pr < p.pr : c < p.c;
	}
};
struct BB {
	AA t;
	int num;
	bool operator < (const BB &p)const {
		return t < p.t;
	}
}U[701000];
int main() {
	int i, j, a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		int t = i, c=0;
		while (t) {
			c++;
			t /= 10;
		}
		Ed[i] = { a,b,c };
		Add_Edge1(a, b, c);
	}
	Dijk1(1);
	int cnt = n;
	for (i = 1; i <= m; i++) {
		int a = Ed[i].a, b = Ed[i].b;
		if (D1[a] > D1[b])swap(a, b);
		if (D1[b] == D1[a] + Ed[i].c) {
			vector<int>TP;
			int t = i;
			while (t) {
				TP.push_back(t % 10);
				t /= 10;
			}
			reverse(TP.begin(), TP.end());
			int st = a;
			for (int j = 0; j < TP.size();j++) {
				int ed;
				if (j == TP.size() - 1)ed = b;
				else ed = ++cnt;
				Add_Edge2(st, ed, TP[j]);
				st = ed;
			}
		}
	}
	int on = n;
	n = cnt;
	for (i = 1; i <= n; i++)DD[i] = 1e9;
	DD[1] = 0;
	Q[++tail] = 1;
	while (head < tail) {
		int x = Q[++head];
		for (auto &t : E[x]) {
			if (DD[t] > DD[x] + 1) {
				DD[t] = DD[x] + 1;
				Q[++tail] = t;
			}
		}
	}
	for (i = 1; i <= n; i++)G[DD[i]].push_back(i);
	for (i = 1; i <= n; i++) {
		int cc = 0;
		for (auto &x : G[i]) {
			AA tp = { 999999999, 9 };
			for (j = 0; j < F[x].size(); j++) {
				int y = F[x][j];
				if (DD[y] + 1 != DD[x])continue;
				AA nt = { Rank[y],FL[x][j] };
				if (nt < tp) {
					tp = nt;
					Path[x] = { y,FL[x][j] };
				}
			}
			U[cc++] = { tp, x };
		}
		sort(U, U + cc);
		int cnt = 0;
		for (j = 0; j < cc; j++) {
			if (j == 0 || U[j - 1].t < U[j].t)cnt++;
			Rank[U[j].num] = cnt;
		}
	}
	for (i = 1; i <= n; i++) {
		for (auto &x : G[i]) {
			Ans[x] = (Ans[Path[x].first] * 10 + Path[x].second) % Mod;
		}
	}
	for (i = 2; i <= on; i++)printf("%lld\n", Ans[i]);
}