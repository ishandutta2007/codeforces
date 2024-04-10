#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#define N_ 601000
#define SZ 524288
using namespace std;
typedef pair<int, int> pii;
int n, m, Q, cc, Num[N_], End[N_], ReNum[N_], EC, cnt2;
int Rotate(int a, int r) {
	a = (a + r) % n;
	if (a == 0)a = n;
	return a;
}
int par[N_][20], Dep[N_];
int up(int a, int d) {
	for (int i = 0; i < 19; i++)if ((d >> i) & 1)a = par[a][i];
	return a;
}



struct UUU {
	int ord[N_], Up[N_], chk[N_], cnt, n, EC, Com[N_], ccom, Com2[N_], ccom2;
	vector<int>GG[N_], HH[N_];
	vector<pii>EE[N_];
	struct Edge {
		int a, b;
	}Ed[N_];

	void Add_Edge(int a, int b) {
		EE[a].push_back({ b,EC });
		EE[b].push_back({ a,EC });
		chk[EC] = 0;
		Ed[EC++] = { a,b };
	}
	void init(int N) {
		n = N;
		EC = 0;
		cnt = 0;
		ccom = 0;
		ccom2 = 0;
		for (int i = 0; i <= n; i++) {
			ord[i] = Com2[i] = Com[i] = Up[i] = 0;
			GG[i].clear();
			EE[i].clear();
			HH[i].clear();
		}
	}
	void DFS4(int a, int pE) {
		ord[a] = ++cnt;
		Com2[a] = ccom2;
		Up[a] = cnt;
		for (auto &t : EE[a]) {
			int x = t.first, num = t.second;
			if (num == pE)continue;
			if (!ord[x]) {
				DFS4(x, num);
				if (ord[a] < Up[x]) {
					chk[num] = 1;
				}
				Up[a] = min(Up[a], Up[x]);
			}
			else {
				Up[a] = min(Up[a], ord[x]);
			}
		}
	}

	void init2() {
		int i;
		for (i = 0; i < EC; i++) {
			if (!chk[i]) {
				GG[Ed[i].a].push_back(Ed[i].b);
				GG[Ed[i].b].push_back(Ed[i].a);
			}
		}
	}
	void DFS5(int a) {
		Com[a] = ccom;
		for (auto &x : GG[a]) {
			if (!Com[x])DFS5(x);
		}
	}

	void Do() {
		for (int i = 1; i <= n; i++) {
			if (!Com2[i]) {
				ccom2++;
				DFS4(i, -1);
			}
		}
		init2();
		for (int i = 1; i <= n; i++) {
			if (!Com[i]) {
				ccom++;
				DFS5(i);
			}
		}
	}
	void DFS3(int a, int pp) {
		Num[a] = ++cnt2;
		ReNum[cnt2] = a;
		par[a][0] = pp;
		for (int i = 0; i < 19; i++)par[a][i + 1] = par[par[a][i]][i];
		for (auto &x : HH[a]) {
			if (!Num[x]) {
				Dep[x] = Dep[a] + 1;
				DFS3(x, a);
			}
		}
		End[a] = cnt2;
	}
	void Do2() {
		int i;
		for (i = 0; i < EC; i++) {
			if (chk[i]) {
				HH[Com[Ed[i].a]].push_back(Com[Ed[i].b]);
				HH[Com[Ed[i].b]].push_back(Com[Ed[i].a]);
			}
		}
		for (i = 1; i <= ccom; i++) {
			if (!Num[i]) {
				DFS3(i, 0);
			}
		}
	}

}AAA, BBB;


int LCA(int a, int b) {
	//if (AAA.Com2[a] != AAA.Com2[b])return 0;
	if (Dep[a] < Dep[b])return LCA(b, a);
	a = up(a, Dep[a] - Dep[b]);
	for (int i = 18; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
int IT[SZ + SZ];
void Put(int b, int e, int x) {
	b += SZ, e += SZ;
	while (b <= e) {
		IT[b] = IT[e] = x;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
int Max(int a) {
	int r = 0;
	a += SZ;
	while (a) {
		r = max(r, IT[a]);
		a >>= 1;
	}
	return r;
}



bool Bicon(vector<int>U) {
	BBB.Do();
	for (int i = 1; i < U.size();i++) {
		if (BBB.Com[U[i]] != BBB.Com[U[i - 1]])return false;
	}
	return true;
}

int Map[N_];

bool OK(vector<int> A, vector<pii> B) {
	int i;
	set<int>Set;
	for (i = 0; i < A.size(); i++) {
		A[i] = AAA.Com[A[i]];
	}
	for (i = 0; i < B.size(); i++) {
		B[i].first = AAA.Com[B[i].first];
		B[i].second = AAA.Com[B[i].second];
	}
	vector<int>T, T2;
	for (auto &t : A)T.push_back(Num[t]);
	for (auto &t : B)T.push_back(Num[t.first]), T.push_back(Num[t.second]);
	sort(T.begin(), T.end());
	T.resize(unique(T.begin(), T.end()) - T.begin());
	for (int i = 1; i < T.size(); i++) {
		int x = LCA(ReNum[T[i - 1]], ReNum[T[i]]);
		if (x) {
			T2.push_back(x);
		}
	}
	for (auto &t : T2)T.push_back(Num[t]);
	sort(T.begin(), T.end());
	T.resize(unique(T.begin(), T.end()) - T.begin());
	int sz = T.size();
	BBB.init(sz);
	for (i = 0; i < T.size(); i++) {
		Map[ReNum[T[i]]] = i + 1;
	}
	for (int i = 0; i < T.size(); i++) {
		int x = ReNum[T[i]];
		int pp = Max(Num[x]);
		if (pp) {
			BBB.Add_Edge(pp, i + 1);
		}
		Put(Num[x], End[x], i + 1);
	}
	for (int i = 0; i < T.size(); i++) {
		int x = ReNum[T[i]];
		Put(Num[x], End[x], 0);
	}
	for (i = 0; i < B.size(); i++) {
		BBB.Add_Edge(Map[B[i].first], Map[B[i].second]);
	}
	for (i = 0; i < A.size(); i++) {
		A[i] = Map[A[i]];
	}
	return Bicon(A);
}
int main() {
	int i, a, b, c, c2, R = 0;
	scanf("%d%d%d", &n, &m, &Q);
	AAA.init(n);
	for (i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		AAA.Add_Edge(a, b);
	}
	AAA.Do();
	AAA.Do2();
	for(int ii=1;ii<=Q;ii++) {
		scanf("%d%d", &c,&c2);
		vector<int>A;
		vector<pii>B;
		A.resize(c);
		B.resize(c2);
		for (i = 0; i < c; i++) {
			scanf("%d", &A[i]);
			A[i] = Rotate(A[i], R);
		}
		for (i = 0; i < c2; i++) {
			scanf("%d%d", &a,&b);
			a = Rotate(a, R);
			b = Rotate(b, R);
			B[i] = { a,b };
		}
		if (OK(A,B)) {
			puts("YES");
			R=(R+ii)%n;
		}
		else puts("NO");
	}
}