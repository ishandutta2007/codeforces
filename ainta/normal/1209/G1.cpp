#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define SZ 262144
#define N_ 201000
#define MaxX 200000
using namespace std;
int n, Q;
struct MnTree {
	int IT[SZ + SZ];
	void init() {
		for (int i = 1; i < SZ + SZ; i++)IT[i] = 1e9;
	}
	void Put(int a, int b) {
		a += SZ;
		IT[a] = b;
		while (a != 1) {
			a >>= 1;
			IT[a] = min(IT[a * 2], IT[a * 2 + 1]);
		}
	}
	int Min(int b, int e) {
		int r = 1e9;
		b += SZ, e += SZ;
		while (b <= e) {
			r = min(r, min(IT[b], IT[e]));
			b = (b + 1) >> 1, e = (e - 1) >> 1;
		}
		return r;
	}
}mIT;
struct MxTree {
	int IT[SZ + SZ];
	void init() {
		for (int i = 1; i < SZ + SZ; i++)IT[i] = 0;
	}
	void Put(int a, int b) {
		a += SZ;
		IT[a] = b;
		while (a != 1) {
			a >>= 1;
			IT[a] = max(IT[a * 2], IT[a * 2 + 1]);
		}
	}
	int Max(int b, int e) {
		int r = 0;
		b += SZ, e += SZ;
		while (b <= e) {
			r = max(r, max(IT[b], IT[e]));
			b = (b + 1) >> 1, e = (e - 1) >> 1;
		}
		return r;
	}
}MIT, GG;

struct SumTree {
	long long IT[SZ + SZ];
	void init() {
		for (int i = 1; i < SZ + SZ; i++)IT[i] = 0;
	}
	void Add(int a, long long b) {
		a += SZ;
		while (a) {
			IT[a] += b;
			a >>= 1;
		}
	}
	long long Sum(int b, int e) {
		long long r = 0;
		b += SZ, e += SZ;
		while (b <= e) {
			if (b & 1)r += IT[b];
			if (!(e & 1))e += IT[e];
			b = (b + 1) >> 1, e = (e - 1) >> 1;
		}
		return r;
	}
}ST;
int w[N_], Bef[N_];
set<int>Set[N_];
struct Range {
	int b, e, c;
	bool operator < (const Range &p)const {
		return b < p.b;
	}
};
vector<Range>G[SZ + SZ];
void Put(int nd, int b, int e, int s, int l, int bb, int ee, int c) {
	if (s > l)return;
	if (s <= b && e <= l) {
		G[nd].push_back({ bb,ee,c });
		return;
	}
	int m = (b + e) >> 1;
	if (s <= m)Put(nd * 2, b, m, s, l, bb, ee, c);
	if (l > m)Put(nd * 2 + 1, m + 1, e, s, l, bb, ee, c);
}
void UDT(int t, int ed) {
	if (!Set[t].empty()) {
		int bb = *Set[t].begin();
		auto it = Set[t].end(); it--;
		int ee = *it;
		int c = Set[t].size();
		Put(1, 0, Q, Bef[t], ed, bb, ee, c);
	}
	Bef[t] = ed + 1;
}
long long Res, RR[30];
struct SS {
	int bb, ee, mi, Mi, Gi;
	long long ds;
};
vector<SS>Save[22];
int CS[22];
void Add(int b, int e, int c, int dep) {
	int bb = min(b, mIT.Min(b, n));
	int ee = max(e, MIT.Max(1, e));
	int g = max(c,GG.Max(bb, ee));
	long long s = ST.Sum(bb, ee);
	Res += g - s;
	Save[dep].push_back({bb, ee, mIT.IT[SZ + ee], MIT.IT[SZ + bb], GG.IT[SZ + bb], g - s});
	mIT.Put(ee, bb);
	MIT.Put(bb, ee);
	GG.Put(bb, g);
	ST.Add(bb, g - s);
}
void Recover(SS t) {
	mIT.Put(t.ee, t.mi);
	MIT.Put(t.bb, t.Mi);
	GG.Put(t.bb, t.Gi);
	ST.Add(t.bb, -t.ds);
}
void Do(int nd, int b, int e, int dep) {
	for (auto &t : G[nd]) {
		Add(t.b, t.e, t.c, dep);
	}
	RR[dep] = Res;
	if (b == e) {
		printf("%lld\n", n-Res);
	}
	else {
		int m = (b + e) >> 1;
		Do(nd * 2, b, m, dep + 1);
		Do(nd * 2 + 1, m + 1, e, dep + 1);
	}
	int sz = Save[dep].size();
	for (int i = sz - 1; i >= 0; i--) {
		Recover(Save[dep][i]);
	}
	Save[dep].clear();
	if(dep)Res = RR[dep - 1];
}
int main() {
	int i, a, b;
	scanf("%d%d", &n, &Q);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		Set[w[i]].insert(i);
	}
	for (i = 1; i <= Q; i++) {
		scanf("%d%d", &a, &b);
		UDT(w[a], i - 1);
		UDT(b, i - 1);
		Set[w[a]].erase(a);
		Set[b].insert(a);
		w[a] = b;
	}
	for (i = 1; i <= MaxX; i++) {
		if (!Set[i].empty()) {
			UDT(i, Q);
		}
	}
	mIT.init();
	MIT.init();
	for (i = 1; i < SZ + SZ; i++) {
		if (G[i].empty())continue;
		sort(G[i].begin(), G[i].end());
		vector<Range>TP;
		int be = -1, ed = -1, c = -1;
		for (auto &t : G[i]) {
			if (ed < t.b) {
				if (ed != -1) {
					TP.push_back({ be,ed,c });
				}
				be = t.b;
				c = 0;
			}
			c = max(c, t.c);
			ed = max(ed,t.e);
		}
		if (ed != -1)TP.push_back({ be,ed,c });
		G[i] = TP;
	}
	Do(1, 0, Q, 0);
}