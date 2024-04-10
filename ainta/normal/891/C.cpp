#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
using namespace std;
int n, m;
struct point {
	int a, b, c;
	bool operator <(const point &p)const {
		return c < p.c;
	}
}w[501000];
struct AA {
	int a, c;
	bool operator <(const AA &p)const {
		return c < p.c;
	}
}ord[501000];
vector<point>G[501000];
vector<vector<int> > P[501000];
vector<int> Num[501000];
int UF[501000], chk[501000], U[501000], Res[501000], S[501000];
int Find(int a) {
	if (a == UF[a])return a;
	return Find(UF[a]);
}

vector<pii> LOG;

bool Merge(int a, int b, bool chk) {
	a = Find(a), b = Find(b);
	if (a != b) {
		if (S[a] > S[b]) {
			swap(a, b);
		}
		if(chk)LOG.push_back({ a, S[a] });
		UF[a] = b;
		S[b] += S[a];
		S[a] = 0;
		return true;
	}
	return false;
}

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].c);
		G[w[i].c].push_back({ w[i].a,w[i].b,i });
	}
	for (i = 1; i <= n; i++)UF[i] = i, S[i] = 1;
	for (i = 1; i <= 500000; i++) {
		for (j = 0; j < G[i].size(); j++) {
			if (Find(G[i][j].a) == Find(G[i][j].b))chk[G[i][j].c] = 1;
		}
		for (j = 0; j < G[i].size(); j++) {
			Merge(G[i][j].a, G[i][j].b, false);
		}
	}
	int Q, c;
	scanf("%d", &Q);
	for (i = 0; i < Q; i++) {
		scanf("%d", &c);
		for (j = 0; j < c; j++) {
			scanf("%d", &U[j]);
		}
		for (j = 0; j < c; j++) {
			if (chk[U[j]])break;
		}
		Res[i] = 1;
		if (j != c) Res[i] = 0;
		if (Res[i] == 0) continue;
		for (j = 0; j < c; j++) {
			ord[j].a = U[j], ord[j].c = w[U[j]].c;
		}
		sort(ord, ord + c);
		vector<int>TP;
		for (j = 0; j < c; j++) {
			TP.push_back(ord[j].a);
			if (j == c - 1 || ord[j].c != ord[j + 1].c) {
				if (TP.size() > 1) {
					P[ord[j].c].push_back(TP);
					Num[ord[j].c].push_back(i);
				}
				TP.clear();
			}
		}
	}
	for (i = 1; i <= n; i++)UF[i] = i, S[i] = 1;
	for (i = 1; i <= 500000; i++) {
		for (j = 0; j < P[i].size(); j++) {
			for (int k = 0; k < P[i][j].size(); k++) {
				int t = P[i][j][k];
				if (!Merge(w[t].a, w[t].b, true)) {
					Res[Num[i][j]] = 0;
				}
			}
			for (int k = LOG.size() - 1; k >= 0; k--) {
				S[LOG[k].first] = LOG[k].second;
				UF[LOG[k].first] = LOG[k].first;
			}
			LOG.clear();
		}
		for (j = 0; j < G[i].size(); j++) {
			Merge(G[i][j].a, G[i][j].b, false);
		}
	}
	for (i = 0; i < Q; i++) {
		if (Res[i])printf("YES\n");
		else printf("NO\n");
	}
}