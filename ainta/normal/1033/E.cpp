#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int UF[610], w[610], EC[610];
vector<int>G[610];
vector<int>T[610];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
int n;
vector<int>VV[2];
vector<int>QQ;
void DFS(int a, int pp, int ck) {
	VV[ck].push_back(a);
	for (auto &x : T[a]) {
		if(x!=pp)DFS(x, a, 1-ck);
	}
}
void Merge(int a, int b) {
	T[a].push_back(b);
	T[b].push_back(a);
	a = Find(a), b = Find(b);
	UF[b] = a;
	for (auto &x : G[b])G[a].push_back(x);
	EC[a] += EC[b];
}
void Clear() {
	QQ.clear();
}
void Put(int a) {
	QQ.push_back(a);
}
int GG[5][5], DEBUG = 0;
void Add_Edge(int a, int b) {
	GG[a][b] = GG[b][a] = 1;
}
int Query() {
	if (!DEBUG) {
		printf("? %d\n", QQ.size());
		for (auto &x : QQ)printf("%d ", x);
		puts("");
		fflush(stdout);
		int a;
		scanf("%d", &a);
		return a;
	}
	int r = 0;
	for (auto &x : QQ)for (auto &y : QQ)if (GG[x][y])r++;
	return r / 2;
}
int Go(int root, int a, vector<int>&TP, bool ck) {
	int b = 0, e = TP.size() - 1, mid, r = 0, i, c;
	while (b <= e) {
		mid = (b + e) >> 1;
		Clear();
		for (i = 0; i <= mid; i++)Put(TP[i]);
		Put(a);
		c = Query();
		if (c) {
			r = mid;
			e = mid - 1;
		}
		else b = mid + 1;
	}
	if(ck) Merge(a, TP[r]);
	return TP[r];
}
int Path[700];
void DFS2(int a, int pp) {
	Path[a] = pp;
	for (auto &x : T[a]) {
		if (x == pp)continue;
		DFS2(x, a);
	}
}
void Print(int a, int st, int ed) {
	DFS2(st, 0);
	int x = ed;
	vector<int>T;
	while (1) {
		T.push_back(x);
		if (x == st)break;
		x = Path[x];
	}
	T.push_back(a);
	printf("N %d\n", T.size());
	for (auto &x : T)printf("%d ", x);
	fflush(stdout);
}
int main() {
	int i, j, k, ss = 0;
	if (!DEBUG) {
		scanf("%d", &n);
	}
	else {
		int m;
		scanf("%d%d", &n, &m);
		for (i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			Add_Edge(a, b);
		}
	}
	for (i = 1; i <= n; i++) {
		UF[i] = i;
	}
	for (i = 1; i <= n; i++) {
		G[i].push_back(i);
		if (i == 1)continue;
		int cnt = 0;
		vector<int>V;
		for (j = 1; j < i; j++) {
			if (Find(j) == j) {
				V.push_back(j);
			}
		}
		int pv = 0;
		while (pv < V.size()) {
			int b = pv, e = V.size() - 1, mid, r = -1, cc = 0;
			while (b <= e) {
				mid = (b + e) >> 1;
				int ec = 0, ec2;
				Clear();
				Put(i);
				for (j = pv; j <= mid; j++) {
					ec += EC[V[j]];
					for (auto &x : G[V[j]]) Put(x);
				}
				ec2 = Query();
				if (ec2 != ec){
					r = mid;
					cc = ec2 - ec;
					e = mid - 1;
				}
				else b = mid + 1;
			}
			if (r == -1)break;
			VV[0].clear();
			VV[1].clear();
			DFS(V[r], 0, 0);

			Clear();
			Put(i);
			for (auto &x : VV[0])Put(x);
			int tp;
			tp = Query();


			Clear();
			Put(i);
			for (auto &x : VV[1])Put(x);
			int tp2;
			tp2 = Query();

			if (tp && tp2) {

				int t1 = Go(V[r], i, VV[1], false);
				int t2 = Go(V[r], i, VV[0], false);
				Print(i, t1, t2);
				return 0;
			}
			else {
				if (tp == 0) {
					Go(V[r], i, VV[1], true);
				}
				else {
					Go(V[r], i, VV[0], true);
				}
			}
			pv = r + 1;
		}
		Clear();
		for (j = 1; j <= i; j++)Put(j);
		int ts = Query();
		EC[Find(i)] += ts - ss;
		ss = ts;
	}
	VV[0].clear();
	VV[1].clear();
	for (i = 1; i <= n; i++) {
		if (Find(i) == i) {
			DFS(i, 0, 0);
		}
	}
	printf("Y %d\n", VV[0].size());
	for (auto &x : VV[0])printf("%d ", x);
}