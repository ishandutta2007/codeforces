#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#define pii pair<int,int>
#define piii pair< pii,int>
#define N_ 101000
using namespace std;
vector<int>E[N_], L[N_];
vector<piii>V[110];
int pL[N_], n, Dep[N_], par[N_][20], Num[N_], cnt, C[N_], PPP[N_], ReNum[N_];
long long BS = 26, Mod[2] = { 1000000007,1000000009 }, po[N_][2];
void DFS(int a, int pp) {
	int i;
	C[a]++;
	par[a][0] = pp;
	for (i = 0; i < 18; i++)par[a][i+1] = par[par[a][i]][i];
	for (i = 0; i < E[a].size();i++) {
		int x = E[a][i];
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		pL[x] = L[a][i];
		DFS(x, a);
		C[a] += C[x];
	}
}
int Up(int a, int d) {
	int i = 0;
	while (d) {
		if (d & 1)a = par[a][i];
		i++; d >>= 1;
	}
	return a;
}
void HLD(int a, int ppp) {
	PPP[a] = ppp;
	Num[a] = ++cnt;
	ReNum[cnt] = a;
	int Mx = -1, pv = -1;
	for (auto &x : E[a]) {
		if (x == par[a][0])continue;
		if (Mx < C[x])Mx = C[x], pv = x;
	}
	if (pv == -1) {
		return;
	}
	HLD(pv, ppp);
	for (auto &x : E[a]) {
		if (x == par[a][0])continue;
		if (x != pv)HLD(x, x);
	}
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	a = Up(a, Dep[a] - Dep[b]);
	int i;
	for (i = 17; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
char p[110];
int m, w[110], q[220];
int Get(int b, int e, int z1, int z2) {
	return lower_bound(V[m].begin(), V[m].end(), piii(pii(z1,z2),e+1)) - lower_bound(V[m].begin(), V[m].end(), piii(pii(z1, z2),b));
}
int Go(int a, int pp, int z1, int z2) {
	int i;
	int l = Dep[a] - Dep[pp];
	if (l < m)return 0;
	int rp = Up(a, l - m), res = 0;
	while (1) {
		int t = PPP[a];
		if (Dep[t] <= Dep[rp]) {
			res += Get(Num[rp], Num[a], z1,z2);
			break;
		}
		else {
			res += Get(Num[t], Num[a], z1,z2);
			a = par[t][0];
		}
	}
	return res;
}
string GetString(int a, int pp, int L) {
	a = Up(a, max(Dep[a] - Dep[pp] - L, 0));
	string t = "";
	L = Dep[a] - Dep[pp];
	if (!L)return t;
	t.resize(L);
	int c = 0;
	while (a != pp) {
		t[c++] = pL[a] + 'a';
		a = par[a][0];
	}
	return t;
}
int oto[220];
int KMP(int LL) {
	int i, res = 0;
	oto[0] = -1;
	for (i = 0; i < m; i++) {
		int t = oto[i];
		while (t != -1 && w[i] != w[t])t = oto[t];
		oto[i + 1] = t + 1;
	}
	int pv = 0;
	for (i = 0; i < LL; i++) {
		while (pv != -1 && w[pv] != q[i])pv = oto[pv];
		pv++;
		if (pv == m)res++;
	}
	return res;
}
int main() {
	int i, a, b, j;
	char pp[3];
	po[0][0]=po[0][1] = 1;
	for (i = 1; i <= 100000; i++)for(j=0;j<2;j++)po[i][j] = po[i - 1][j] * BS % Mod[j];
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		scanf("%s", pp);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(pp[0] - 'a');
		L[b].push_back(pp[0] - 'a');
	}
	DFS(1, 0);
	HLD(1, 1);
	for (i = 1; i <= n; i++) {
		int x = i;
		long long s1 = 0, s2 = 0;
		for (j = 0; j < min(100, Dep[i]); j++) {
			s1 = (s1 * BS + pL[x]) % Mod[0];
			s2 = (s2 * BS + pL[x]) % Mod[1];
			x = par[x][0];
			V[j + 1].push_back({ {s1,s2},Num[i] });
		}
	}
	for (i = 1; i <= 100; i++)if (!V[i].empty())sort(V[i].begin(), V[i].end());
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &a, &b);
		scanf("%s", p);
		long long s1[2] = { 0,0 }, s2[2] = { 0,0 };
		for (i = 0; p[i]; i++)w[i] = p[i] - 'a';
		m = i;
		for (i = 0; p[i]; i++) {
			for (j = 0; j < 2; j++) {
				s1[j] = (s1[j] + w[i] * po[i][j]) % Mod[j];
				s2[j] = (s2[j] * BS + w[i]) % Mod[j];
			}
		}
		int l = LCA(a, b);
		int res = Go(a, l, s2[0],s2[1]);
		res += Go(b, l, s1[0],s1[1]);

		string t1 = GetString(a, l, m - 1);
		string t2 = GetString(b, l, m - 1);
		int c = 0;
		for (i = 0; i < t1.size(); i++)q[c++] = t1[i] - 'a';
		for (i = t2.size()-1; i >= 0; i--)q[c++] = t2[i] - 'a';
		res += KMP(c);
		printf("%d\n", res);
	}

}