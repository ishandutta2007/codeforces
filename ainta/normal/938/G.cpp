#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define pii pair<int,int>
#define N_ 201000
#define SZ 262144
using namespace std;
int n, QC, cnt;
map<int, int>VV[N_], UU[N_];
struct Query {
	int a, b;
}Q[N_];
struct Edge {
	int a, b, c;
};
vector<Edge>V[SZ + SZ];
void Put(int nd, int b, int e, int s, int l, int x, int y, int d) {
	if (nd == 1) {
		//printf("!!! %d %d %d  : %d %d\n", x, y, d, s, l);
	}
	if (b == s && e == l) {
		V[nd].push_back({ x,y,d });
		return;
	}
	int m = (b + e) >> 1;
	if (s <= m)Put(nd * 2, b, m, s, min(m, l), x, y, d);
	if (l > m)Put(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x, y, d);
}

int UF[N_], UD[N_], ddd, C[N_], MM[30];

vector<int>Save[20], S2[20];

int Find2(int a) {
	if (a == UF[a])return a;
	ddd ^= UD[a];
	return Find2(UF[a]);
}

pii Find(int a) {
	ddd = 0;
	int t = Find2(a);
	return { t,ddd };
}

void Put(int d, int dep) {
	int i;
	for (i = 29; i >= 0; i--) {
		if ((d >> i) & 1) {
			if (!MM[i]) {
				MM[i] = d;
				S2[dep].push_back(i);
				return;
			}
			d ^= MM[i];
		}
	}
}

void Merge(int a, int b, int c, int dep) {
	pii t1 = Find(a);
	pii t2 = Find(b);
	if (t1.first != t2.first) {
		int d = t1.second^t2.second^c;
		int aa = t1.first;
		int bb = t2.first;
		if (C[aa] < C[bb]) {
			UF[aa] = bb;
			UD[aa] = d;
			C[bb] += C[aa];
			Save[dep].push_back(aa);
		}
		else {
			UF[bb] = aa;
			UD[bb] = d;
			C[aa] += C[bb];
			Save[dep].push_back(bb);
		}
		return;
	}
	int d = t1.second^t2.second^c;
	Put(d, dep);
}

void Rollback(int dep) {
	for (int i = Save[dep].size() - 1; i >= 0; i--) {
		int a = Save[dep][i];
		C[UF[a]] -= C[a];
		UD[a] = 0;
		UF[a] = a;
	}
	for (int i = S2[dep].size() - 1; i >= 0; i--) {
		MM[S2[dep][i]] = 0;
	}
	Save[dep].clear();
	S2[dep].clear();
}

int Calc(int d) {
	int i;
	for (i = 29; i >= 0; i--) {
		if (MM[i] && ((d >> i) & 1)) {
			d ^= MM[i];
		}
	}
	return d;
}

void Do(int nd, int b, int e, int dep) {
	for (auto &tp : V[nd]) {
		Merge(tp.a, tp.b, tp.c, dep);
	}
	if (b == e) {
		if (b <= cnt) {
			pii t1 = Find(Q[b].a);
			pii t2 = Find(Q[b].b);
			printf("%d\n", Calc(t1.second^t2.second));
		}
		Rollback(dep);
		return;
	}
	int m = (b + e) >> 1;
	Do(nd * 2, b, m, dep + 1);
	Do(nd * 2+1, m+1, e, dep + 1);

	Rollback(dep);
}

int main() {
	int i, a, b, c, ck, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (a > b)swap(a, b);
		UU[a][b] = c;
		VV[a][b] = 1;
	}
	scanf("%d", &QC);
	for (i = 1; i <= QC; i++) {
		scanf("%d", &ck);
		if (ck == 3) {
			cnt++;
			scanf("%d%d", &Q[cnt].a, &Q[cnt].b);
		}
		else if (ck == 2) {
			scanf("%d%d", &a, &b);
			if (a > b)swap(a, b);
			int t = VV[a][b];
			if (t && t <= cnt) {
				Put(1, 1, SZ, t, cnt, a, b, UU[a][b]);
			}
			VV[a][b] = 0;
		}
		else {
			scanf("%d%d%d", &a, &b, &c);
			if (a > b)swap(a, b);
			UU[a][b] = c;
			VV[a][b] = cnt + 1;
		}
	}
	for (i = 1; i <= n; i++) {
		for (auto &tp : VV[i]) {
			int t = tp.second;
			if (t <= cnt && t) {
				Put(1, 1, SZ, t, cnt, i, tp.first, UU[i][tp.first]);
			}
		}
	}
	for (i = 1; i <= n; i++)UF[i] = i, UD[i] = 0, C[i] = 1;
	Do(1, 1, SZ, 0);
}