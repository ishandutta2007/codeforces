#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 501000
using namespace std;
int n, Up[N_], Down[N_], Dep[N_], par[N_][20], End[N_], ST[N_], ED[N_];
long long Mod = 1000000007;
vector<int>E[N_];
int GoUp(int a, int d) {
	for (int i = 0; i < 19; i++)if ((d >> i) & 1)a = par[a][i];
	return a;
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	a = GoUp(a, Dep[a] - Dep[b]);
	for (int i = 18; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
void DFS(int a, int pp) {
	par[a][0] = pp;
	for (int i = 0; i < 19; i++)par[a][i + 1] = par[par[a][i]][i];
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		DFS(x, a);
	}
}
int w[N_];
struct Edge {
	int a, b;
};
vector<Edge>G[N_];
void Add_Edge(int a, int b, int c) {
	G[a].push_back({ b,c });
}
void Put(vector<int> &P) {
	int sz = P.size();
	ST[P[0]] = P[1];
	ED[P[sz - 1]] = P[sz - 2];
	for (int i = 1; i < sz - 1; i++) {
		Add_Edge(P[i], P[i - 1], P[i + 1]);
	}
}
bool Add(int a, int b) {
	if (a == 0)return true;
	if (End[a])return false;
	End[a]++;
	if (a == b)return false;
	int l = LCA(a, b), ta = a, tb = b;
	vector<int>P;
	while (ta != l) {
		P.push_back(ta);
		if (Up[ta]) return false;
		Up[ta]++;
		ta = par[ta][0];
	}
	vector<int>TP;
	while (tb != l) {
		if (Down[tb])return false;
		TP.push_back(tb);
		Down[tb]++;
		tb = par[tb][0];
	}
	reverse(TP.begin(), TP.end());
	P.push_back(l);
	for (auto &t : TP)P.push_back(t);
	Put(P);
	return true;
}
int Num[N_], Deg[N_], Q[N_];
long long F[N_], InvF[N_];
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
int Nxt[N_];
vector<int>T[N_];
long long Calc(int a) {
	int i;
	for (i = 0; i < E[a].size(); i++) {
		Num[E[a][i]] = i + 1;
	}
	int sz = E[a].size();
	for (i = 0; i < G[a].size(); i++) {
		G[a][i].a = Num[G[a][i].a];
		G[a][i].b = Num[G[a][i].b];
	}
	int st = Num[ST[a]], ed = Num[ED[a]];


	for (i = 1; i <= sz; i++) {
		Deg[i] = 0;
		T[i].clear();
	}
	for (auto &t : G[a]) {
		Deg[t.b]++;
		T[t.a].push_back(t.b);
	}
	for (i = 1; i <= sz; i++) {
		if (st && i != st)T[st].push_back(i), Deg[i]++;
		if (ed && i != ed)T[i].push_back(ed), Deg[ed]++;
	}
	int head = 0, tail = 0;
	for (i = 1; i <= sz; i++)if (!Deg[i])Q[++tail] = i;
	while (head < tail) {
		int x = Q[++head];
		for (auto &t : T[x]) {
			Deg[t]--;
			if (!Deg[t])Q[++tail] = t;
		}
	}
	if (tail != sz)return 0ll;

	for (i = 1; i <= sz; i++) {
		Deg[i] = 0;
		Nxt[i] = 0;
	}
	for (auto &t : G[a]) {
		Deg[t.b]++;
		Nxt[t.a] = t.b;
	}
	int c = 0;
	for (i = 1; i <= sz; i++) {
		if (Deg[i] == 0) {
			vector<int>Z;
			int t = i;
			Z.push_back(t);
			while (Nxt[t]) {
				t = Nxt[t];
				Z.push_back(t);
			}
			if (Z[0] == st && Z.back() == ed) {
				if (Z.size() != sz)return 0ll;
			}
			if (Z[0] == st || Z.back() == ed)continue;
			c++;
		}
	}
	return F[c];
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	F[0] = 1;
	for (i = 1; i <= n; i++)F[i] = F[i - 1] * i%Mod;
	InvF[n] = Pow(F[n], Mod - 2);
	for (i = n; i >= 1; i--)InvF[i - 1] = InvF[i] * i%Mod;
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		if (!Add(w[i], i)) {
			puts("0");
			return 0;
		}
	}
	long long res = 1;
	for (i = 1; i <= n; i++) {
		res = res * Calc(i) % Mod;
	}
	printf("%lld\n", res);
}