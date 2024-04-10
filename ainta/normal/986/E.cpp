#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define N_ 101000
#define pii pair<int,int>
using namespace std;
int n, w[101000], CQ, par[101000][20], Dep[N_], p[10100], pc;
vector<int>E[N_];
struct Query {
	int a, b, x;
}Q[N_];
int Up(int a, int d) {
	int i = 0;
	while (d) {
		if (d & 1)a = par[a][i];
		i++; d >>= 1;
	}
	return a;
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	a = Up(a, Dep[a] - Dep[b]);
	for (int i = 17; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
vector<pii>V;
map<int, int>Map;
vector<vector<int> >G[N_*2];
vector<vector<pii> >U[N_*2];
void Fact(int a) {
	int i;
	V.clear();
	for (i = 0; p[i]*p[i]<=a; i++) {
		if (a%p[i] == 0) {
			int c = 0;
			while (a%p[i] == 0) {
				a /= p[i];
				c++;
			}
			V.push_back({ p[i],c });
		}
	}
	if (a != 1) {
		V.push_back({ a,1 });
	}
}
int Num[N_], Ed[N_], cc;
void DFS(int a, int pp) {
	par[a][0] = pp;
	int i;
	Num[a] = ++cc;
	for (i = 0; i < 18; i++)par[a][i + 1] = par[par[a][i]][i];
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		DFS(x, a);
	}
	Ed[a] = cc;
}
const int SZ = 131072;
int IT[SZ + SZ];
void Put(int a, int c) {
	int b = Num[a]+SZ;
	int e = Ed[a]+SZ;
	while (b <= e) {
		if (b & 1)IT[b] += c;
		if (!(e & 1))IT[e] += c;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
int Get(int a) {
	if (!a)return 0;
	int t = a + SZ, s  = 0;
	while (t) {
		s += IT[t];
		t >>= 1;
	}
	return s;
}
long long res[N_], Mod = 1000000007;
long long Pow(long long a, int b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
void Go(int num, Query q, int x) {
	int a = q.a, b = q.b;
	int l = LCA(a, b);
	int c = Get(Num[a]) + Get(Num[b]) - Get(Num[l]) - Get(Num[par[l][0]]);
	if (c < 0) {
		printf("!!");
	}
	res[num] = res[num] * Pow(x, c) % Mod;
}
int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output2.txt", "w", stdout);
	int i, a, b, j ,cnt = 0;
	for (i = 2; i <= 10000; i++) {
		for (j = 2; j*j <= i; j++)if (i%j == 0)break;
		if (j*j > i)p[pc++] = i;
	}
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	scanf("%d", &CQ);
	for (i = 1; i <= CQ; i++)scanf("%d%d%d", &Q[i].a, &Q[i].b, &Q[i].x);
	for (i = 1; i <= n; i++) {
		Fact(w[i]);
		for (auto &tp : V) {
			if (!Map.count(tp.first)) Map[tp.first] = ++cnt;
			int t = Map[tp.first];
			if (G[t].size() <= tp.second + 1) {
				G[t].resize(tp.second + 1);
			}
			G[t][tp.second].push_back(i);
		}
	}
	for (i = 1; i <= cnt; i++)U[i].resize(G[i].size());
	for (i = 1; i <= CQ; i++) {
		res[i] = 1;
		Fact(Q[i].x);
		for (auto &tp : V) {
			if (!Map.count(tp.first))continue;
			int t = Map[tp.first];
			int r = 1;
			for (j = 0; j < G[t].size(); j++) {
				U[t][j].push_back( { i,r });
				if (j < tp.second)r = r * tp.first;
			}
		}
	}
	DFS(1, 0);
	for (i = 1; i <= cnt; i++) {
		for (j = 0; j < G[i].size(); j++) {
			for (auto &t : G[i][j]) {
				Put(t, 1);
			}
			for (auto &t : U[i][j]) {
				Go(t.first, Q[t.first], t.second);
			}
			for (auto &t : G[i][j]) {
				Put(t, -1);
			}
		}
	}
	for (i = 1; i <= CQ; i++)printf("%lld\n", res[i]);
}